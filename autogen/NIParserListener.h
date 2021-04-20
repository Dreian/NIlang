
// Generated from grammars/NIParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NIParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by NIParser.
 */
class  NIParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(NIParser::ProgContext *ctx) = 0;
  virtual void exitProg(NIParser::ProgContext *ctx) = 0;

  virtual void enterExp(NIParser::ExpContext *ctx) = 0;
  virtual void exitExp(NIParser::ExpContext *ctx) = 0;

  virtual void enterTerm(NIParser::TermContext *ctx) = 0;
  virtual void exitTerm(NIParser::TermContext *ctx) = 0;

  virtual void enterInt_term(NIParser::Int_termContext *ctx) = 0;
  virtual void exitInt_term(NIParser::Int_termContext *ctx) = 0;

  virtual void enterBool_term(NIParser::Bool_termContext *ctx) = 0;
  virtual void exitBool_term(NIParser::Bool_termContext *ctx) = 0;

  virtual void enterIdent_term(NIParser::Ident_termContext *ctx) = 0;
  virtual void exitIdent_term(NIParser::Ident_termContext *ctx) = 0;

  virtual void enterPar_exp(NIParser::Par_expContext *ctx) = 0;
  virtual void exitPar_exp(NIParser::Par_expContext *ctx) = 0;

  virtual void enterNot_exp(NIParser::Not_expContext *ctx) = 0;
  virtual void exitNot_exp(NIParser::Not_expContext *ctx) = 0;

  virtual void enterMinus_exp(NIParser::Minus_expContext *ctx) = 0;
  virtual void exitMinus_exp(NIParser::Minus_expContext *ctx) = 0;

  virtual void enterBinop_exp(NIParser::Binop_expContext *ctx) = 0;
  virtual void exitBinop_exp(NIParser::Binop_expContext *ctx) = 0;

  virtual void enterBool_binop_exp(NIParser::Bool_binop_expContext *ctx) = 0;
  virtual void exitBool_binop_exp(NIParser::Bool_binop_expContext *ctx) = 0;

  virtual void enterStat(NIParser::StatContext *ctx) = 0;
  virtual void exitStat(NIParser::StatContext *ctx) = 0;

  virtual void enterAssignment(NIParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(NIParser::AssignmentContext *ctx) = 0;

  virtual void enterIf_then(NIParser::If_thenContext *ctx) = 0;
  virtual void exitIf_then(NIParser::If_thenContext *ctx) = 0;

  virtual void enterIf_then_else(NIParser::If_then_elseContext *ctx) = 0;
  virtual void exitIf_then_else(NIParser::If_then_elseContext *ctx) = 0;

  virtual void enterWhile_loop(NIParser::While_loopContext *ctx) = 0;
  virtual void exitWhile_loop(NIParser::While_loopContext *ctx) = 0;

  virtual void enterPrint(NIParser::PrintContext *ctx) = 0;
  virtual void exitPrint(NIParser::PrintContext *ctx) = 0;

  virtual void enterVar_decl(NIParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(NIParser::Var_declContext *ctx) = 0;

  virtual void enterVar_specs(NIParser::Var_specsContext *ctx) = 0;
  virtual void exitVar_specs(NIParser::Var_specsContext *ctx) = 0;

  virtual void enterStat_seq(NIParser::Stat_seqContext *ctx) = 0;
  virtual void exitStat_seq(NIParser::Stat_seqContext *ctx) = 0;

  virtual void enterBegin_end(NIParser::Begin_endContext *ctx) = 0;
  virtual void exitBegin_end(NIParser::Begin_endContext *ctx) = 0;


};

