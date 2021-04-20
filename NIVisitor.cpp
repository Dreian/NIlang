#include "antlr4-runtime.h"

#include "autogen/NIParser.h"
#include "autogen/NIParserBaseVisitor.h"

#include "AST.h"
#include "NIVisitor.h"

antlrcpp::Any NIVisitor::visitProg(NIParser::ProgContext *ctx) {
  auto varBlock = visit(ctx->children[0]);
  auto programBody = visit(ctx->children[1]);
  auto vb = varBlock.as<AST::VarBlockNode*>();
  auto pb = programBody.as<AST::StatementNode*>();
  return new AST::ProgNode(varBlock.as<AST::VarBlockNode*>(),
                           programBody.as<AST::StatementNode*>(),
                           ctx->start->getLine(), ctx->start->getCharPositionInLine());
}

antlrcpp::Any NIVisitor::visitBegin_end(NIParser::Begin_endContext *ctx) {
  auto exp = visit(ctx->children[1]);
  return exp.as<AST::StatementNode*>();
}

antlrcpp::Any NIVisitor::visitPar_exp(NIParser::Par_expContext *ctx) {
  auto exp = visit(ctx->children[1]);
  return exp.as<AST::ExpressionNode*>();
}

antlrcpp::Any NIVisitor::visitBool_binop_exp(NIParser::Bool_binop_expContext *ctx) {
    AST::BinOp op = AST::AND;
    if (ctx->OR()) {
      op = AST::OR;
    }
    auto left = visit(ctx->children[0]);
    auto right = visit(ctx->children[2]);
    auto node = new AST::BinopExpressionNode(left.as<AST::ExpressionNode*>(),
                                            right.as<AST::ExpressionNode*>(),
                                            op, ctx->start->getLine(), ctx->start->getCharPositionInLine());
    return (AST::ExpressionNode*)(node);
}

antlrcpp::Any NIVisitor::visitAssignment(NIParser::AssignmentContext *ctx) {
  auto body = visit(ctx->children[2]);
  auto node = new AST::AssignmentNode(ctx->children[0]->getText(),
                                      body.as<AST::ExpressionNode*>(),
                                      ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::StatementNode*)(node);
}

antlrcpp::Any NIVisitor::visitIf_then(NIParser::If_thenContext *ctx) {
  auto cond = visit(ctx->children[1]);
  auto then_branch = visit(ctx->children[3]);
  auto node = new AST::IfNode(cond.as<AST::ExpressionNode*>(),
                              then_branch.as<AST::StatementNode*>(),
                              ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::StatementNode*)(node);
}

antlrcpp::Any NIVisitor::visitIf_then_else(NIParser::If_then_elseContext *ctx) {
  auto cond = visit(ctx->children[1]);
  auto then_branch = visit(ctx->children[3]);
  auto else_branch = visit(ctx->children[5]);
  auto node = new AST::IfElseNode(cond.as<AST::ExpressionNode*>(),
                                  then_branch.as<AST::StatementNode*>(),
                                  else_branch.as<AST::StatementNode*>(),
                                  ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::StatementNode*)(node); 
}

antlrcpp::Any NIVisitor::visitVar_decl(NIParser::Var_declContext *ctx) {
  return new AST::VarDeclNode(ctx->children[0]->getText(),
                              AST::string_to_type(ctx->children[2]->getText()),
                              ctx->start->getLine(), ctx->start->getCharPositionInLine());
}

antlrcpp::Any NIVisitor::visitVar_specs(NIParser::Var_specsContext *ctx) {
  int n_children = ctx->children.size();
  std::vector<AST::VarDeclNode*> children;
  for (int i = 1; i < n_children; i += 2) {
    auto visited = visit(ctx->children[i]);
    children.push_back(visited.as<AST::VarDeclNode*>());
  }
  return new AST::VarBlockNode(children, ctx->start->getLine(), ctx->start->getCharPositionInLine());
}

antlrcpp::Any NIVisitor::visitWhile_loop(NIParser::While_loopContext *ctx) {
  auto cond = visit(ctx->children[1]);
  auto body = visit(ctx->children[3]);
  auto node = new AST::WhileNode(cond.as<AST::ExpressionNode*>(),
                                 body.as<AST::StatementNode*>(),
                                 ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::StatementNode*)(node);
}

antlrcpp::Any NIVisitor::visitPrint(NIParser::PrintContext *ctx) {
  auto exp = visit(ctx->children[2]);
  auto node =  new AST::PrintNode(exp.as<AST::ExpressionNode*>(),
                                  ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::StatementNode*)(node);
}

antlrcpp::Any NIVisitor::visitMinus_exp(NIParser::Minus_expContext *ctx) {
  auto exp = visit(ctx->children[1]);
  auto node = new AST::UnopExpressionNode(exp.as<AST::ExpressionNode*>(),
                                          AST::NEG, ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return exp.as<AST::ExpressionNode*>();
}

antlrcpp::Any NIVisitor::visitNot_exp(NIParser::Not_expContext *ctx) {
  auto exp = visit(ctx->children[1]);
  auto node = new AST::UnopExpressionNode(exp.as<AST::ExpressionNode*>(),
                                          AST::NOT, ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::ExpressionNode*)(node);
}

antlrcpp::Any NIVisitor::visitBinop_exp(NIParser::Binop_expContext *ctx) {
  AST::BinOp op = AST::PLUS;
  if (ctx->PLUS()) {
    op = AST::PLUS;
  } else if (ctx->MINUS()) {
    op = AST::MINUS;
  } else if (ctx->TIMES()) {
    op = AST::TIMES;
  } else if (ctx->DIV()) {
    op = AST::DIV;
  } else if (ctx->EQ()) {
    op = AST::EQ;
  } else if (ctx->LEQ()) {
    op = AST::LEQ;
  } else if (ctx->GEQ()) {
    op = AST::GEQ;
  } else if (ctx->LT()) {
    op = AST::LT;
  } else if (ctx->GT()) {
    op = AST::GT;
  }
  auto left = visit(ctx->children[0]);
  auto right = visit(ctx->children[2]);
  auto node = new AST::BinopExpressionNode(left.as<AST::ExpressionNode*>(),
                                           right.as<AST::ExpressionNode*>(),
                                           op, ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::ExpressionNode*)(node);
}

antlrcpp::Any NIVisitor::visitIdent_term(NIParser::Ident_termContext *ctx) {
  auto node = new AST::IdentifierNode(ctx->getText(),
                                      ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::ExpressionNode*)(node);
}

antlrcpp::Any NIVisitor::visitInt_term(NIParser::Int_termContext *ctx) {
  auto node = new AST::IntConstantNode(std::stoi(ctx->getText()),
                                       ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::ExpressionNode*)(node);
}

antlrcpp::Any NIVisitor::visitBool_term(NIParser::Bool_termContext *ctx) {
  AST::BoolNode *node;
  if (ctx->getText().compare("true")) {
    node = new AST::BoolNode(true, ctx->start->getLine(), ctx->start->getCharPositionInLine());
  } else {
    node = new AST::BoolNode(false, ctx->start->getLine(), ctx->start->getCharPositionInLine());
  }
  return (AST::ExpressionNode*)(node);
}

antlrcpp::Any NIVisitor::visitStat_seq(NIParser::Stat_seqContext *ctx) {
  std::vector<AST::StatementNode*> children;
  int n_children = 1 + ctx->children.size() / 2;
  for (int i = 0; i < n_children; i++) {
    auto visited = visit(ctx->children[2 * i]);
    children.push_back(visited.as<AST::StatementNode*>());
  }
  auto node = new AST::StatementBlockNode(children, ctx->start->getLine(), ctx->start->getCharPositionInLine());
  return (AST::StatementNode*)(node);
}