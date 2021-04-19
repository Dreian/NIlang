
// Generated from NIParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NIParserVisitor.h"


/**
 * This class provides an empty implementation of NIParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  NIParserBaseVisitor : public NIParserVisitor {
public:

  virtual antlrcpp::Any visitProg(NIParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExp(NIParser::ExpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(NIParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt_term(NIParser::Int_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_term(NIParser::Bool_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdent_term(NIParser::Ident_termContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPar_exp(NIParser::Par_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNot_exp(NIParser::Not_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMinus_exp(NIParser::Minus_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinop_exp(NIParser::Binop_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_binop_exp(NIParser::Bool_binop_expContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStat(NIParser::StatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(NIParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_then(NIParser::If_thenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_then_else(NIParser::If_then_elseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_loop(NIParser::While_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(NIParser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_decl(NIParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_specs(NIParser::Var_specsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStat_seq(NIParser::Stat_seqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStat_block(NIParser::Stat_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBegin_end(NIParser::Begin_endContext *ctx) override {
    return visitChildren(ctx);
  }


};

