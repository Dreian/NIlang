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
protected:
  int line_no;
  int col_no;
  ASTNode(int, int);
public:
  virtual Type typeCheck(TypeEnv&, bool&) = 0;
  virtual llvm::Value *codegen(Compiler::Components&) = 0;
};

class VarDeclNode : public ASTNode {
private:
  IdentifierName variable;
  Type type;
public:
  VarDeclNode(IdentifierName, Type, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class VarBlockNode : public ASTNode {
private:
  std::vector<VarDeclNode*> varDecls;
public:
  VarBlockNode(std::vector<VarDeclNode*>&, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class StatementNode : public ASTNode {
protected:
  StatementNode(int line_no, int col_no) : ASTNode(line_no, col_no) {};
};
class ExpressionNode : public ASTNode {
protected:
  ExpressionNode(int line_no, int col_no) : ASTNode(line_no, col_no) {};
};

class StatementBlockNode: public StatementNode {
private:
  std::vector<StatementNode*> statements;
public:
  StatementBlockNode(std::vector<StatementNode*>&, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class ProgNode : public ASTNode {
private:
  VarBlockNode *varBlock;
  StatementNode *statBlock;
public:
  ProgNode(VarBlockNode*, StatementNode*, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class AssignmentNode : public StatementNode {
private:
  IdentifierName variable;
  ExpressionNode *expressionNode;
public:
  AssignmentNode(IdentifierName, ExpressionNode*, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IfNode : public StatementNode {
private:
  ExpressionNode *condition;
  StatementNode *thenBranch;
public:
  IfNode(ExpressionNode*, StatementNode*, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IfElseNode : public StatementNode {
private:
  ExpressionNode *condition;
  StatementNode *thenBranch;
  StatementNode *elseBranch;
public:
  IfElseNode(ExpressionNode*, StatementNode*, StatementNode*, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class WhileNode : public StatementNode {
private:
  ExpressionNode *condition;
  StatementNode *body;
public:
  WhileNode(ExpressionNode*, StatementNode*, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class PrintNode : public StatementNode {
private:
  ExpressionNode *printed_exp;
public:
  PrintNode(ExpressionNode*, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class BinopExpressionNode : public ExpressionNode {
private:
  ExpressionNode *left_exp, *right_exp;
  BinOp op;
public:
  BinopExpressionNode(ExpressionNode*, ExpressionNode*, BinOp, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class UnopExpressionNode : public ExpressionNode {
private:
  ExpressionNode *exp;
  UnOp op;
public:
  UnopExpressionNode(ExpressionNode*, UnOp, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IntConstantNode : public ExpressionNode {
private:
  int underlying_int;
public:
  IntConstantNode(int, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class BoolNode : public ExpressionNode {
private:
  bool underlying_bool;
public:
  BoolNode(bool, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

class IdentifierNode : public ExpressionNode {
private:
  IdentifierName id_name;
public:
  IdentifierNode(IdentifierName, int, int);
  virtual Type typeCheck(TypeEnv&, bool&) override;
  virtual llvm::Value *codegen(Compiler::Components&) override;
};

}