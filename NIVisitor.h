#include "antlr4-runtime.h"

#include "autogen/NIParser.h"
#include "autogen/NIParserBaseVisitor.h"

class NIVisitor : public NIParserBaseVisitor {
public:
  antlrcpp::Any visitProg(NIParser::ProgContext *ctx) override;
  antlrcpp::Any visitBegin_end(NIParser::Begin_endContext *ctx) override;
  antlrcpp::Any visitPar_exp(NIParser::Par_expContext *ctx) override;
  antlrcpp::Any visitBool_binop_exp(NIParser::Bool_binop_expContext *ctx) override;
  antlrcpp::Any visitAssignment(NIParser::AssignmentContext *ctx) override;
  antlrcpp::Any visitIf_then(NIParser::If_thenContext *ctx) override;
  antlrcpp::Any visitIf_then_else(NIParser::If_then_elseContext *ctx) override;
  antlrcpp::Any visitVar_decl(NIParser::Var_declContext *ctx) override;
  antlrcpp::Any visitVar_specs(NIParser::Var_specsContext *ctx) override;
  antlrcpp::Any visitWhile_loop(NIParser::While_loopContext *ctx) override;
  antlrcpp::Any visitPrint(NIParser::PrintContext *ctx) override;
  antlrcpp::Any visitMinus_exp(NIParser::Minus_expContext *ctx) override;
  antlrcpp::Any visitNot_exp(NIParser::Not_expContext *ctx) override;
  antlrcpp::Any visitBinop_exp(NIParser::Binop_expContext *ctx) override;
  antlrcpp::Any visitIdent_term(NIParser::Ident_termContext *ctx) override;
  antlrcpp::Any visitInt_term(NIParser::Int_termContext *ctx) override;
  antlrcpp::Any visitBool_term(NIParser::Bool_termContext *ctx) override;
  antlrcpp::Any visitStat_seq(NIParser::Stat_seqContext *ctx) override;
};