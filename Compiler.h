#include <string>
#include <unordered_map>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

namespace Compiler {

typedef std::string IdentifierName;

struct Components {
  llvm::LLVMContext llvmCtx;
  llvm::Function *fun;
  llvm::IRBuilder<> builder;
  std::unique_ptr<llvm::Module> llvmModule;
  std::unordered_map<IdentifierName, llvm::AllocaInst*> symbols;
  Components(std::string);
};

}
