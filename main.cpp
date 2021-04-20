#include <fstream>
#include <iostream>
#include <map>

#include "antlr4-runtime.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#include "autogen/NILexer.h"
#include "autogen/NIParser.h"

#include "AST.h"
#include "ErrorListeners.h"
#include "NIVisitor.h"

std::map<char, std::string> options;
std::string input_filename;
std::string output_filename = "out.o";
bool print_ir = false;
bool print_asm = false;
bool should_print_usage = false;

void print_usage() {
  std::cout << "USAGE:"
            << " nilang [options] <path_to_source> [path_to_output]"
            << std::endl << std::endl
            << "OPTIONS:" << std::endl;
  for (auto entry: options) {
    std::cout << " -" << entry.first << ": " << entry.second << std::endl;
  }
}

void process_args(int argc, const char** argv) {
  bool found_input = false;
  bool custom_target = false;
  bool found_output = false;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
        case 'h':
          should_print_usage = true;
        case 'l':
          print_ir = true;
          break;
        case 's':
          print_asm = true;
          break;
        case 't':
          custom_target = true;
          break;
        default:
          std::cerr << "Unknown option: " << argv[i] << std::endl;
          should_print_usage = true;
          return;
      }
    } else if (found_input) {
      if (custom_target && !found_output) {
        output_filename = argv[i];
        found_output = true;
      } else {
        std::cerr << "Superfluous argument: " << argv[i] << std::endl;
        should_print_usage = true;
      }
    } else {
      input_filename = argv[i];
      found_input = true;
    }
  }
  if (!found_input) {
    should_print_usage = true;
  }
}

int output_llvm_ir(Compiler::Components &comp) {
  std::error_code ec;
  llvm::raw_fd_ostream dest(output_filename, ec, llvm::sys::fs::OF_None);
  if (ec) {
    llvm::errs() << "Could not open file: " << ec.message();
    return 1;
  }
  comp.llvmModule->print(dest, nullptr);
  return 0;
}

int output_program(Compiler::Components &comp) {
  // write IR and stop?
  if (print_ir) {
    return output_llvm_ir(comp);
  }

  auto targetTriple = llvm::sys::getDefaultTargetTriple();
  llvm::InitializeAllTargetInfos();
  llvm::InitializeAllTargets();
  llvm::InitializeAllTargetMCs();
  llvm::InitializeAllAsmParsers();
  llvm::InitializeAllAsmPrinters();
  std::string Error;
  auto target = llvm::TargetRegistry::lookupTarget(targetTriple, Error);
  if (!target) {
    llvm::errs() << Error;
    return 1;
  }

  auto cpu = "generic";
  auto features = "";
  llvm::TargetOptions opt;
  auto rm = llvm::Optional<llvm::Reloc::Model>();
  auto targetMachine = target->createTargetMachine(targetTriple, cpu, features, opt, rm);
  comp.llvmModule->setDataLayout(targetMachine->createDataLayout());
  comp.llvmModule->setTargetTriple(targetTriple);
  std::error_code ec;
  llvm::raw_fd_ostream dest(output_filename, ec, llvm::sys::fs::OF_None);
  if (ec) {
    llvm::errs() << "Could not open file: " << ec.message();
    return 1;
  }

  llvm::legacy::PassManager pass;
  auto fileType = llvm::CGFT_ObjectFile;
  if (print_asm) {
    fileType = llvm::CGFT_AssemblyFile;
  }
  if (targetMachine->addPassesToEmitFile(pass, dest, nullptr, fileType)) {
    llvm::errs() << "TargetMachine can't emit a file of this type";
    return 1;
  }
  pass.run(*comp.llvmModule);
  dest.flush();
}

int main(int argc, const char** argv) {
  
  options['h'] = "show this message";
  options['l'] = "don't compile, output resulting LLVM IR";
  options['s'] = "don't compile, output resulting assembly";
  options['t'] = "specify output name as an additional argument";

  process_args(argc, argv);
  if (should_print_usage) {
    print_usage();
    return 0;
  }

  // input from the file
  std::ifstream stream;
  std::ios_base::iostate exceptionMask = stream.exceptions()
                                         | std::ios::failbit;
  stream.exceptions(exceptionMask);
  antlr4::ANTLRInputStream input;
  try {
    stream.open(input_filename, std::ifstream::in);
  } catch (std::ifstream::failure &e) {
    std::cerr << "Failed to process file: " << input_filename << std::endl;
    std::cerr << e.what() << std::endl;
    return 0;
  }
  input = antlr4::ANTLRInputStream(stream);

  // lexing
  NILexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  tokens.fill();
  stream.close();
  
  // parsing
  NIParser parser(&tokens);
  parser.removeErrorListeners();
  bool syntax_errors = false;
  parser.addErrorListener(new NIParserErrorListener(syntax_errors));
  antlr4::tree::ParseTree *tree;
  try {
    tree = parser.prog();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  if (syntax_errors) {
    std::cerr << "Exiting..." << std::endl;
    return 1;
  }

  // turning the parse tree into an AST
  NIVisitor visitor;
  AST::ProgNode *ast = visitor.visit(tree).as<AST::ProgNode*>();

  // type check
  AST::TypeEnv prog_type_env;
  bool type_errors = false;
  ast->typeCheck(prog_type_env, type_errors);
  if (type_errors) {
    std::cerr << "Exiting..." << std::endl;
    return 1;
  }

  // generate LLVM code
  Compiler::Components comp(input_filename);
  std::vector<llvm::Type*> printf_args;
  printf_args.push_back(llvm::Type::getInt8PtrTy(comp.llvmCtx));
  llvm::Function::Create(llvm::FunctionType::get(comp.builder.getInt32Ty(), printf_args, true),
                         llvm::Function::ExternalLinkage, "printf",
                         comp.llvmModule.get());
  comp.fun = llvm::Function::Create(llvm::FunctionType::get(comp.builder.getInt32Ty(), false),
                                    llvm::Function::ExternalLinkage, "main",
                                    comp.llvmModule.get());
  auto c = ast->codegen(comp);
  
  // whole backend fits here!
  return output_program(comp);
}
