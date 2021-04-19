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

VarDeclNode::VarDeclNode(IdentifierName variable, Type type) :
  variable(variable), type(type) {};

Type VarDeclNode::typeCheck(TypeEnv& typeEnv) {
  if (typeEnv.find(variable) != typeEnv.end()) {
    throw 1;
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
}

VarBlockNode::VarBlockNode(std::vector<VarDeclNode*>& varDecls) : varDecls(varDecls) {};

Type VarBlockNode::typeCheck(TypeEnv& typeEnv) {
  for (auto decl : varDecls) {
    decl->typeCheck(typeEnv);
  }
  return NA;
}

llvm::Value *VarBlockNode::codegen(Compiler::Components &comp) {
  for (auto decl : varDecls) {
    decl->codegen(comp);
  }
}


StatementBlockNode::StatementBlockNode(std::vector<StatementNode*>& statements) :
  statements(statements) {};

Type StatementBlockNode::typeCheck(TypeEnv& typeEnv) {
  for (auto statement : statements) {
    if (statement->typeCheck(typeEnv) != UNIT) {
      throw 77;
    }
  }
  return UNIT;
}

llvm::Value *StatementBlockNode::codegen(Compiler::Components &comp) {
  for (auto statement : statements) {
    statement->codegen(comp);
  }
}

ProgNode::ProgNode(VarBlockNode *varBlock, StatementBlockNode *statBlock) :
  varBlock(varBlock), statBlock(statBlock) {};

Type ProgNode::typeCheck(TypeEnv& typeEnv) {
  varBlock->typeCheck(typeEnv);
  statBlock->typeCheck(typeEnv);
  return NA;
}
  
llvm::Value *ProgNode::codegen(Compiler::Components &comp) {
  comp.builder.SetInsertPoint(llvm::BasicBlock::Create(comp.llvmCtx, "entry", comp.fun));
  varBlock->codegen(comp);
  statBlock->codegen(comp);
  comp.builder.CreateRet(llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(comp.llvmCtx), 0));
}

AssignmentNode::AssignmentNode(IdentifierName variable, ExpressionNode *expressionNode) :
  variable(variable), expressionNode(expressionNode) {};

Type AssignmentNode::typeCheck(TypeEnv &typeEnv) {
  if (typeEnv.find(variable) == typeEnv.end()) {
    throw 2;
  }
  Type var_type = typeEnv[variable];
  Type expr_type = expressionNode->typeCheck(typeEnv);
  if (var_type != expr_type) {
    throw 3;
  }
  return UNIT;
}

llvm::Value *AssignmentNode::codegen(Compiler::Components &comp) {
  llvm::Value *rhs = expressionNode->codegen(comp);
  llvm::Value *var = comp.symbols[variable];
  comp.builder.CreateStore(rhs, var);
}

IfNode::IfNode(ExpressionNode *condNode, StatementBlockNode *thenNode) :
  condition(condNode), thenBranch(thenNode) {}

Type IfNode::typeCheck(TypeEnv &typeEnv) {
  if (condition->typeCheck(typeEnv) != BOOL) {
    throw 4;
  }
  if (thenBranch->typeCheck(typeEnv) != UNIT) {
    throw 5;
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
}

IfElseNode::IfElseNode(ExpressionNode *condNode, StatementBlockNode *thenNode, StatementBlockNode *elseNode) :
  condition(condNode), thenBranch(thenNode), elseBranch(elseNode) {};

Type IfElseNode::typeCheck(TypeEnv &typeEnv) {
  if (condition->typeCheck(typeEnv) != BOOL) {
    throw 4;
  }
  if (thenBranch->typeCheck(typeEnv) != UNIT) {
    throw 5;
  }
  if (elseBranch->typeCheck(typeEnv) != UNIT) {
    throw 6;
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
}

WhileNode::WhileNode(ExpressionNode *condition, StatementBlockNode *body):
  condition(condition), body(body) {}

Type WhileNode::typeCheck(TypeEnv& typeEnv) {
  if (condition->typeCheck(typeEnv) != BOOL) {
    throw 88;
  }
  if (body->typeCheck(typeEnv) != UNIT) {
    throw 99;
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
}

PrintNode::PrintNode(ExpressionNode *to_print) : printed_exp(to_print) {};

Type PrintNode::typeCheck(TypeEnv &typeEnv) {
  if (printed_exp->typeCheck(typeEnv) != INT) {
    throw 101;
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

BinopExpressionNode::BinopExpressionNode(ExpressionNode *left, ExpressionNode *right, BinOp op):
  left_exp(left), right_exp(right), op(op) {}

Type BinopExpressionNode::typeCheck(TypeEnv &typeEnv) {
  Type typeLeft = left_exp->typeCheck(typeEnv);
  Type typeRight = right_exp->typeCheck(typeEnv);
  if (typeLeft != typeRight) {
    throw 7;
  }
  switch (op)
  {
  case PLUS:
  case MINUS:
  case TIMES:
  case DIV:
    if (typeLeft != INT) {
      throw 8;
    }
    return INT;
  case GT:
  case LT:
  case EQ:
  case NEQ:
  case GEQ:
  case LEQ:
    if (typeLeft != INT) {
      throw 9;
    }
    return BOOL;
  case AND:
  case OR:
    if (typeLeft != BOOL) {
      throw 91;
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
}

UnopExpressionNode::UnopExpressionNode(ExpressionNode *exp, UnOp op):
  exp(exp), op(op) {}

Type UnopExpressionNode::typeCheck(TypeEnv &typeEnv) {
  Type type = exp->typeCheck(typeEnv);
  switch (op)
  {
  case NEG:
    if (type != INT) {
      throw 10;
    }
    return INT;
  case NOT:
    if (type != BOOL) {
      throw 11;
    }
    return BOOL;
  default:
    return NA;
  }
}

llvm::Value *UnopExpressionNode::codegen(Compiler::Components &typeEnv) {}

IntConstantNode::IntConstantNode(int number): underlying_int(number) {};

Type IntConstantNode::typeCheck(TypeEnv &typeEnv) {
  return INT;
}

llvm::Value *IntConstantNode::codegen(Compiler::Components &comp) {
  return llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(comp.llvmCtx),
                                underlying_int, true);
}

BoolNode::BoolNode(bool truthy): underlying_bool(truthy) {};

Type BoolNode::typeCheck(TypeEnv &typeEnv) {
  return BOOL;
}

 llvm::Value *BoolNode::codegen(Compiler::Components &comp) {
  return llvm::ConstantInt::get(llvm::IntegerType::getInt1Ty(comp.llvmCtx),
                                underlying_bool);
}

IdentifierNode::IdentifierNode(IdentifierName id_name): id_name(id_name) {};

Type IdentifierNode::typeCheck(TypeEnv &typeEnv) {
  if (typeEnv.find(id_name) == typeEnv.end()) {
    throw 222;
  }
  return typeEnv[id_name];
}

llvm::Value *IdentifierNode::codegen(Compiler::Components &comp) {
  return comp.builder.CreateLoad(comp.symbols[id_name], id_name.c_str());

}

}