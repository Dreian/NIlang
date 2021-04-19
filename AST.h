#include <string>
#include <unordered_map>
#include <vector>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Value.h"

#include "Compiler.h"

namespace AST {

enum Type {INT, BOOL, UNIT, NA};
enum BinOp {PLUS, TIMES, MINUS, DIV, AND, OR, LT, GT, LEQ, GEQ, EQ, NEQ};
enum UnOp {NEG, NOT};

typedef std::string IdentifierName;
typedef std::unordered_map<IdentifierName, Type> TypeEnv; 

Type string_to_type(std::string type);
std::string type_to_string(Type type);

class ASTNode;
class ProgNode;
class VarBlockNode;
class VarDeclNode;
class StatementBlockNode;
class StatementNode;
class ExpressionNode;
class AssignmentNode;
class IfNode;
class IfElseNode;
class WhileNode;
class PrintNode;
class BinopExpressionNode;
class UnopExpressionNode;
class IntConstantNode;
class BoolNode; 

class ASTNode {
public:
  virtual Type typeCheck(TypeEnv&) = 0;
  virtual llvm::Value *codegen(Compiler::Components&) = 0;
};

class VarDeclNode : public ASTNode {
private:
  IdentifierName variable;
  Type type;
public:
  VarDeclNode(IdentifierName, Type);
  virtual Type typeCheck(TypeEnv&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class VarBlockNode : public ASTNode {
private:
  std::vector<VarDeclNode*> varDecls;
public:
  VarBlockNode(std::vector<VarDeclNode*>&);
  virtual Type typeCheck(TypeEnv&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class StatementNode : public ASTNode {};
class ExpressionNode : public ASTNode {};

class StatementBlockNode: public ASTNode {
private:
  std::vector<StatementNode*> statements;
public:
  StatementBlockNode(std::vector<StatementNode*>&);
  virtual Type typeCheck(TypeEnv&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class ProgNode : public ASTNode {
private:
  VarBlockNode *varBlock;
  StatementBlockNode *statBlock;
public:
  ProgNode(VarBlockNode *varBlock, StatementBlockNode *statBlock);
  virtual Type typeCheck(TypeEnv&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class AssignmentNode : public StatementNode {
private:
  IdentifierName variable;
  ExpressionNode *expressionNode;
public:
  AssignmentNode(IdentifierName variable, ExpressionNode *expressionNode);
  virtual Type typeCheck(TypeEnv&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IfNode : public StatementNode {
private:
  ExpressionNode *condition;
  StatementBlockNode *thenBranch;
public:
  IfNode(ExpressionNode *condNode, StatementBlockNode *thenNode);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IfElseNode : public StatementNode {
private:
  ExpressionNode *condition;
  StatementBlockNode *thenBranch;
  StatementBlockNode *elseBranch;
public:
  IfElseNode(ExpressionNode *condNode, StatementBlockNode *thenNode, StatementBlockNode *elseNode);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class WhileNode : public StatementNode {
private:
  ExpressionNode *condition;
  StatementBlockNode *body;
public:
  WhileNode(ExpressionNode *condition, StatementBlockNode *body);
  virtual Type typeCheck(TypeEnv& typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class PrintNode : public StatementNode {
private:
  ExpressionNode *printed_exp;
public:
  PrintNode(ExpressionNode *to_print);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class BinopExpressionNode : public ExpressionNode {
private:
  ExpressionNode *left_exp, *right_exp;
  BinOp op;
public:
  BinopExpressionNode(ExpressionNode *left, ExpressionNode *right, BinOp op);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class UnopExpressionNode : public ExpressionNode {
private:
  ExpressionNode *exp;
  UnOp op;
public:
  UnopExpressionNode(ExpressionNode *exp, UnOp op);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IntConstantNode : public ExpressionNode {
private:
  int underlying_int;
public:
  IntConstantNode(int);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class BoolNode : public ExpressionNode {
private:
  bool underlying_bool;
public:
  BoolNode(bool truthy);
  virtual Type typeCheck(TypeEnv&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IdentifierNode : public ExpressionNode {
private:
  IdentifierName id_name;
public:
  IdentifierNode(IdentifierName id_name);
  virtual Type typeCheck(TypeEnv &typeEnv) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

}