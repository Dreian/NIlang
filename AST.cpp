#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"
#include "llvm/Support/raw_ostream.h"

#include "AST.h"

namespace AST {

Type string_to_type(std::string type) {
  if (type == "integer") {
    return INT;
  }
  if (type == "boolean") {
    return BOOL;
  }
  return NA;
}

std::string type_to_string(Type type) {
  switch (type) {
  case INT:
    return "integer";
  case BOOL:
    return "boolean";
  case UNIT:
    return "unit";
  default:
    return "N/A";
  }
}

std::string op_to_string(BinOp op) {
  switch (op) {
  case PLUS:
    return "+";
  case MINUS:
    return "-";
  case TIMES:
    return "*";
  case DIV:
    return "div";
  case AND:
    return "and";
  case OR:
    return "or";
  case LT:
    return "<";
  case GT:
    return ">";
  case LEQ:
    return "<=";
  case GEQ:
    return ">=";
  case EQ:
    return "=";
  case NEQ:
    return "<>";
  }
}

ASTNode::ASTNode(int line_no, int col_no) : line_no(line_no), col_no(col_no) {};

VarDeclNode::VarDeclNode(IdentifierName variable, Type type, int line_no, int col_no) :
  ASTNode(line_no, col_no), variable(variable), type(type) {};

Type VarDeclNode::typeCheck(TypeEnv& typeEnv, bool& error) {
  if (typeEnv.find(variable) != typeEnv.end()) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  variable " << variable << " already declared" << std::endl;
    error = true;
  } 
  typeEnv[variable] = type;
  return NA;
}

llvm::Value *VarDeclNode::codegen(Compiler::Components &comp) {
  if (type == INT) {
    comp.symbols[variable] = comp.builder.CreateAlloca(llvm::IntegerType::getInt32Ty(comp.llvmCtx), 0,
                                                       variable.c_str());
  } else if (type == BOOL) {
    comp.symbols[variable] = comp.builder.CreateAlloca(llvm::IntegerType::getInt1Ty(comp.llvmCtx), 0,
                                                       variable.c_str());
  }
  return nullptr;
}

VarBlockNode::VarBlockNode(std::vector<VarDeclNode*>& varDecls, int line_no, int col_no) :
  ASTNode(line_no, col_no), varDecls(varDecls) {};

Type VarBlockNode::typeCheck(TypeEnv& typeEnv, bool &error) {
  for (auto decl : varDecls) {
    decl->typeCheck(typeEnv, error);
  }
  return NA;
}

llvm::Value *VarBlockNode::codegen(Compiler::Components &comp) {
  for (auto decl : varDecls) {
    decl->codegen(comp);
  }
  return nullptr;
}

StatementBlockNode::StatementBlockNode(std::vector<StatementNode*>& statements, int line_no, int col_no) :
  StatementNode(line_no, col_no), statements(statements) {};

Type StatementBlockNode::typeCheck(TypeEnv& typeEnv, bool &error) {
  for (auto statement : statements) {
    if (statement->typeCheck(typeEnv, error) != UNIT) {
      std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
                << "  only statements can be sequenced" << std::endl;
      error = true;
    }
  }
  return UNIT;
}

llvm::Value *StatementBlockNode::codegen(Compiler::Components &comp) {
  for (auto statement : statements) {
    statement->codegen(comp);
  }
  return nullptr;
}

ProgNode::ProgNode(VarBlockNode *varBlock, StatementNode *statBlock, int line_no, int col_no) :
  ASTNode(line_no, col_no), varBlock(varBlock), statBlock(statBlock) {};

Type ProgNode::typeCheck(TypeEnv& typeEnv, bool &error) {
  varBlock->typeCheck(typeEnv, error);
  statBlock->typeCheck(typeEnv, error);
  return NA;
}
  
llvm::Value *ProgNode::codegen(Compiler::Components &comp) {
  comp.builder.SetInsertPoint(llvm::BasicBlock::Create(comp.llvmCtx, "entry", comp.fun));
  varBlock->codegen(comp);
  statBlock->codegen(comp);
  comp.builder.CreateRet(llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(comp.llvmCtx), 0));
  return nullptr;
}

AssignmentNode::AssignmentNode(IdentifierName variable, ExpressionNode *expressionNode, int line_no, int col_no) :
  StatementNode(line_no, col_no), variable(variable), expressionNode(expressionNode) {};

Type AssignmentNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  if (typeEnv.find(variable) == typeEnv.end()) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  undeclared variable " << variable << std::endl;
    error = true;
  }
  Type var_type = typeEnv[variable];
  Type expr_type = expressionNode->typeCheck(typeEnv, error);
  if (var_type != expr_type) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  cannot assign " << type_to_string(expr_type)
              << " to a variable of type " << type_to_string(var_type) << std::endl;
    error = true;
  }
  return UNIT;
}

llvm::Value *AssignmentNode::codegen(Compiler::Components &comp) {
  llvm::Value *rhs = expressionNode->codegen(comp);
  llvm::Value *var = comp.symbols[variable];
  comp.builder.CreateStore(rhs, var);
  return nullptr;
}

IfNode::IfNode(ExpressionNode *condNode, StatementNode *thenNode, int line_no, int col_no) :
  StatementNode(line_no, col_no), condition(condNode), thenBranch(thenNode) {}

Type IfNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  if (condition->typeCheck(typeEnv, error) != BOOL) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  condition must be a boolean expression" << std::endl;
    error = true;
  }
  if (thenBranch->typeCheck(typeEnv, error) != UNIT) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  body of a conditional must be a statement" << std::endl;
    error = true;
  }
  return UNIT;
}

llvm::Value *IfNode::codegen(Compiler::Components &comp) {
  llvm::Value *condV = condition->codegen(comp);
  llvm::BasicBlock *cont = llvm::BasicBlock::Create(comp.llvmCtx, "if.cont", comp.fun);
  llvm::BasicBlock *ifBody = llvm::BasicBlock::Create(comp.llvmCtx, "if.then", comp.fun);
  condV = comp.builder.CreateIsNotNull(condV);
  comp.builder.CreateCondBr(condV, ifBody, cont);
  comp.builder.SetInsertPoint(ifBody);
  thenBranch->codegen(comp);
  if (comp.builder.GetInsertBlock() != nullptr){
    comp.builder.CreateBr(cont);
  }
  comp.builder.SetInsertPoint(cont);
  return nullptr;
}

IfElseNode::IfElseNode(ExpressionNode *condNode, StatementNode *thenNode, StatementNode *elseNode, int line_no, int col_no) :
  StatementNode(line_no, col_no), condition(condNode), thenBranch(thenNode), elseBranch(elseNode) {};

Type IfElseNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  if (condition->typeCheck(typeEnv, error) != BOOL) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  condition must be a boolean expression" << std::endl;
    error = true;
  }
  if (thenBranch->typeCheck(typeEnv, error) != UNIT) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  then branch of a conditional must be a statement" << std::endl;
    error = true;
  }
  if (elseBranch->typeCheck(typeEnv, error) != UNIT) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  else branch of a conditional must be a statement" << std::endl;
    error = true;
  }
  return UNIT;
}

llvm::Value *IfElseNode::codegen(Compiler::Components &comp) {
  llvm::Value *condV = condition->codegen(comp);
  llvm::BasicBlock *cont = llvm::BasicBlock::Create(comp.llvmCtx, "if.cont", comp.fun);
  llvm::BasicBlock *ifThen = llvm::BasicBlock::Create(comp.llvmCtx, "if.then", comp.fun);
  llvm::BasicBlock *ifElse = llvm::BasicBlock::Create(comp.llvmCtx, "if.else", comp.fun);
  condV = comp.builder.CreateIsNotNull(condV);
  comp.builder.CreateCondBr(condV, ifThen, ifElse);
  comp.builder.SetInsertPoint(ifThen);
  thenBranch->codegen(comp);
  if (comp.builder.GetInsertBlock() != nullptr){
    comp.builder.CreateBr(cont);
  }
  comp.builder.SetInsertPoint(ifElse);
  elseBranch->codegen(comp);
  if (comp.builder.GetInsertBlock() != nullptr){
    comp.builder.CreateBr(cont);
  }
  comp.builder.SetInsertPoint(cont);
  return nullptr;
}

WhileNode::WhileNode(ExpressionNode *condition, StatementNode *body, int line_no, int col_no):
  StatementNode(line_no, col_no), condition(condition), body(body) {}

Type WhileNode::typeCheck(TypeEnv& typeEnv, bool &error) {
  if (condition->typeCheck(typeEnv, error) != BOOL) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  loop condition must be a boolean" << std::endl;
    error = true;
  }
  if (body->typeCheck(typeEnv, error) != UNIT) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  loop body must be a statement" << std::endl;
    error = true;
  }
  return UNIT;
}

llvm::Value *WhileNode::codegen(Compiler::Components &comp) {
  llvm::BasicBlock *whileCond = llvm::BasicBlock::Create(comp.llvmCtx, "while.cond", comp.fun);
  comp.builder.CreateBr(whileCond);
  comp.builder.SetInsertPoint(whileCond);
  llvm::Value *condV = condition->codegen(comp);
  llvm::BasicBlock *cont = llvm::BasicBlock::Create(comp.llvmCtx, "while.cont", comp.fun);
  llvm::BasicBlock *whileBody = llvm::BasicBlock::Create(comp.llvmCtx, "while.body", comp.fun);
  condV = comp.builder.CreateIsNotNull(condV);
  comp.builder.CreateCondBr(condV, whileBody, cont);
  comp.builder.SetInsertPoint(whileBody);
  body->codegen(comp);
  if (comp.builder.GetInsertBlock() != nullptr){
    comp.builder.CreateBr(whileCond);
  }
  comp.builder.SetInsertPoint(cont);
  return nullptr;
}

PrintNode::PrintNode(ExpressionNode *to_print, int line_no, int col_no) :
  StatementNode(line_no, col_no), printed_exp(to_print) {};

Type PrintNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  if (printed_exp->typeCheck(typeEnv, error) != INT) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  only integer-valued expressions can be printed" << std::endl;
    error = true;
  }
  return UNIT;
}

llvm::Value *PrintNode::codegen(Compiler::Components &comp) {
  auto v = printed_exp->codegen(comp);
  std::vector<llvm::Value*> print_args;
  llvm::Value *format_str = comp.builder.CreateGlobalStringPtr("%d\n");
  print_args.push_back(format_str);
  print_args.push_back(v);
  return comp.builder.CreateCall(comp.llvmModule->getFunction("printf"), print_args);
}

BinopExpressionNode::BinopExpressionNode(ExpressionNode *left, ExpressionNode *right, BinOp op, int line_no, int col_no):
  ExpressionNode(line_no, col_no), left_exp(left), right_exp(right), op(op) {}

Type BinopExpressionNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  Type typeLeft = left_exp->typeCheck(typeEnv, error);
  Type typeRight = right_exp->typeCheck(typeEnv, error);
  if (typeLeft != typeRight) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  operand types do not match ("
              << type_to_string(typeLeft) << " and " << type_to_string(typeRight)
              << ")" << std::endl;
    error = true;
  }
  switch (op)
  {
  case PLUS:
  case MINUS:
  case TIMES:
  case DIV:
    if (typeLeft != INT) {
      std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
                << "  operands of operator " << op_to_string(op)
                << " must be of type integer" << std::endl;
      error = true;
    }
    return INT;
  case GT:
  case LT:
  case EQ:
  case NEQ:
  case GEQ:
  case LEQ:
    if (typeLeft != INT) {
      std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
                << "  operands of operator " << op_to_string(op)
                << " must be of type integer" << std::endl;
      error = true;
    }
    return BOOL;
  case AND:
  case OR:
    if (typeLeft != BOOL) {
      std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
                << "  operands of operator " << op_to_string(op)
                << " must be of type boolean" << std::endl;
      error = true;
    }
    return BOOL;
  default:
    return NA;
  }
}

llvm::Value *BinopExpressionNode::codegen(Compiler::Components &comp) {
  llvm::Value *left = left_exp->codegen(comp);
  llvm::Value *right = right_exp->codegen(comp);
  switch (op) {
  case PLUS:
    return comp.builder.CreateAdd(left, right, "addtmp");
  case MINUS:
    return comp.builder.CreateSub(left, right, "subtmp");
  case TIMES:
    return comp.builder.CreateMul(left, right, "multmp");
  case DIV:
    return comp.builder.CreateSDiv(left, right, "divtmp");
  case AND:
    return comp.builder.CreateAnd(left, right, "addtmp");
  case OR:
    return comp.builder.CreateOr(left, right, "ortmp");
  case EQ:
    return comp.builder.CreateICmpEQ(left, right, "eqtmp");
  case NEQ:
    return comp.builder.CreateICmpNE(left, right, "neqtmp");
  case GT:
    return comp.builder.CreateICmpSGT(left, right, "gttmp");
  case GEQ:
    return comp.builder.CreateICmpSGE(left, right, "geqtmp");
  case LT:
    return comp.builder.CreateICmpSLT(left, right, "ltttmp");
  case LEQ:
    return comp.builder.CreateICmpSLE(left, right, "leqtmp");
  }
  return nullptr;
}

UnopExpressionNode::UnopExpressionNode(ExpressionNode *exp, UnOp op, int line_no, int col_no):
  ExpressionNode(line_no, col_no), exp(exp), op(op) {}

Type UnopExpressionNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  Type type = exp->typeCheck(typeEnv, error);
  switch (op)
  {
  case NEG:
    if (type != INT) {
      std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
                << "  operand of unary operator - must be an integer expression" << std::endl;
      error = true;
    }
    return INT;
  case NOT:
    if (type != BOOL) {
      std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
                << "  operand of unary operator - must be a boolean expression" << std::endl;
      error = true;
    }
    return BOOL;
  default:
    return NA;
  }
}

llvm::Value *UnopExpressionNode::codegen(Compiler::Components &comp) {
  // FORGOT ABOUT TODO!!!!
  llvm::Value *arg = exp->codegen(comp);
  switch (op) {
  case NEG:
    return comp.builder.CreateNeg(arg, "negtmp");
  case NOT:
    return comp.builder.CreateNot(arg, "nottmp");
  }
  return nullptr;
}

IntConstantNode::IntConstantNode(int number, int line_no, int col_no) :
  ExpressionNode(line_no, col_no), underlying_int(number) {};

Type IntConstantNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  return INT;
}

llvm::Value *IntConstantNode::codegen(Compiler::Components &comp) {
  return llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(comp.llvmCtx),
                                underlying_int, true);
}

BoolNode::BoolNode(bool truthy, int line_no, int col_no) :
  ExpressionNode(line_no, col_no), underlying_bool(truthy) {};

Type BoolNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  return BOOL;
}

 llvm::Value *BoolNode::codegen(Compiler::Components &comp) {
  return llvm::ConstantInt::get(llvm::IntegerType::getInt1Ty(comp.llvmCtx),
                                underlying_bool);
}

IdentifierNode::IdentifierNode(IdentifierName id_name, int line_no, int col_no) :
  ExpressionNode(line_no, col_no), id_name(id_name) {};

Type IdentifierNode::typeCheck(TypeEnv &typeEnv, bool &error) {
  if (typeEnv.find(id_name) == typeEnv.end()) {
    std::cerr << "Error on line " << line_no << ", column " << col_no << ":" << std::endl
              << "  undeclared variable " << id_name << std::endl;
    error = true;
  }
  return typeEnv[id_name];
}

llvm::Value *IdentifierNode::codegen(Compiler::Components &comp) {
  return comp.builder.CreateLoad(comp.symbols[id_name], id_name.c_str());
}

}
