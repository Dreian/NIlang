
// Generated from grammars/NIParser.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"
#include "NIParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by NIParser.
 */
class  NIParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by NIParser.
   */
    virtual antlrcpp::Any visitProg(NIParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitExp(NIParser::ExpContext *context) = 0;

    virtual antlrcpp::Any visitTerm(NIParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitInt_term(NIParser::Int_termContext *context) = 0;

    virtual antlrcpp::Any visitBool_term(NIParser::Bool_termContext *context) = 0;

    virtual antlrcpp::Any visitIdent_term(NIParser::Ident_termContext *context) = 0;

    virtual antlrcpp::Any visitPar_exp(NIParser::Par_expContext *context) = 0;

    virtual antlrcpp::Any visitNot_exp(NIParser::Not_expContext *context) = 0;

    virtual antlrcpp::Any visitMinus_exp(NIParser::Minus_expContext *context) = 0;

    virtual antlrcpp::Any visitBinop_exp(NIParser::Binop_expContext *context) = 0;

    virtual antlrcpp::Any visitBool_binop_exp(NIParser::Bool_binop_expContext *context) = 0;

    virtual antlrcpp::Any visitStat(NIParser::StatContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(NIParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitIf_then(NIParser::If_thenContext *context) = 0;

    virtual antlrcpp::Any visitIf_then_else(NIParser::If_then_elseContext *context) = 0;

    virtual antlrcpp::Any visitWhile_loop(NIParser::While_loopContext *context) = 0;

    virtual antlrcpp::Any visitPrint(NIParser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(NIParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitVar_specs(NIParser::Var_specsContext *context) = 0;

    virtual antlrcpp::Any visitStat_seq(NIParser::Stat_seqContext *context) = 0;

    virtual antlrcpp::Any visitBegin_end(NIParser::Begin_endContext *context) = 0;


};

