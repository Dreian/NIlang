
// Generated from grammars/NIParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NIParserListener.h"


/**
 * This class provides an empty implementation of NIParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  NIParserBaseListener : public NIParserListener {
public:

  virtual void enterProg(NIParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(NIParser::ProgContext * /*ctx*/) override { }

  virtual void enterExp(NIParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(NIParser::ExpContext * /*ctx*/) override { }

  virtual void enterTerm(NIParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(NIParser::TermContext * /*ctx*/) override { }

  virtual void enterInt_term(NIParser::Int_termContext * /*ctx*/) override { }
  virtual void exitInt_term(NIParser::Int_termContext * /*ctx*/) override { }

  virtual void enterBool_term(NIParser::Bool_termContext * /*ctx*/) override { }
  virtual void exitBool_term(NIParser::Bool_termContext * /*ctx*/) override { }

  virtual void enterIdent_term(NIParser::Ident_termContext * /*ctx*/) override { }
  virtual void exitIdent_term(NIParser::Ident_termContext * /*ctx*/) override { }

  virtual void enterPar_exp(NIParser::Par_expContext * /*ctx*/) override { }
  virtual void exitPar_exp(NIParser::Par_expContext * /*ctx*/) override { }

  virtual void enterNot_exp(NIParser::Not_expContext * /*ctx*/) override { }
  virtual void exitNot_exp(NIParser::Not_expContext * /*ctx*/) override { }

  virtual void enterMinus_exp(NIParser::Minus_expContext * /*ctx*/) override { }
  virtual void exitMinus_exp(NIParser::Minus_expContext * /*ctx*/) override { }

  virtual void enterBinop_exp(NIParser::Binop_expContext * /*ctx*/) override { }
  virtual void exitBinop_exp(NIParser::Binop_expContext * /*ctx*/) override { }

  virtual void enterBool_binop_exp(NIParser::Bool_binop_expContext * /*ctx*/) override { }
  virtual void exitBool_binop_exp(NIParser::Bool_binop_expContext * /*ctx*/) override { }

  virtual void enterStat(NIParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(NIParser::StatContext * /*ctx*/) override { }

  virtual void enterAssignment(NIParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(NIParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterIf_then(NIParser::If_thenContext * /*ctx*/) override { }
  virtual void exitIf_then(NIParser::If_thenContext * /*ctx*/) override { }

  virtual void enterIf_then_else(NIParser::If_then_elseContext * /*ctx*/) override { }
  virtual void exitIf_then_else(NIParser::If_then_elseContext * /*ctx*/) override { }

  virtual void enterWhile_loop(NIParser::While_loopContext * /*ctx*/) override { }
  virtual void exitWhile_loop(NIParser::While_loopContext * /*ctx*/) override { }

  virtual void enterPrint(NIParser::PrintContext * /*ctx*/) override { }
  virtual void exitPrint(NIParser::PrintContext * /*ctx*/) override { }

  virtual void enterVar_decl(NIParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(NIParser::Var_declContext * /*ctx*/) override { }

  virtual void enterVar_specs(NIParser::Var_specsContext * /*ctx*/) override { }
  virtual void exitVar_specs(NIParser::Var_specsContext * /*ctx*/) override { }

  virtual void enterStat_seq(NIParser::Stat_seqContext * /*ctx*/) override { }
  virtual void exitStat_seq(NIParser::Stat_seqContext * /*ctx*/) override { }

  virtual void enterBegin_end(NIParser::Begin_endContext * /*ctx*/) override { }
  virtual void exitBegin_end(NIParser::Begin_endContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

