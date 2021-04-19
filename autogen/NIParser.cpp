
// Generated from NIParser.g4 by ANTLR 4.9


#include "NIParserListener.h"
#include "NIParserVisitor.h"

#include "NIParser.h"


using namespace antlrcpp;
using namespace antlr4;

NIParser::NIParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

NIParser::~NIParser() {
  delete _interpreter;
}

std::string NIParser::getGrammarFileName() const {
  return "NIParser.g4";
}

const std::vector<std::string>& NIParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& NIParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

NIParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::ProgContext::BEGIN() {
  return getToken(NIParser::BEGIN, 0);
}

NIParser::Stat_seqContext* NIParser::ProgContext::stat_seq() {
  return getRuleContext<NIParser::Stat_seqContext>(0);
}

tree::TerminalNode* NIParser::ProgContext::END() {
  return getToken(NIParser::END, 0);
}

tree::TerminalNode* NIParser::ProgContext::DOT() {
  return getToken(NIParser::DOT, 0);
}

tree::TerminalNode* NIParser::ProgContext::EOF() {
  return getToken(NIParser::EOF, 0);
}

NIParser::Var_specsContext* NIParser::ProgContext::var_specs() {
  return getRuleContext<NIParser::Var_specsContext>(0);
}


size_t NIParser::ProgContext::getRuleIndex() const {
  return NIParser::RuleProg;
}

void NIParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void NIParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


antlrcpp::Any NIParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

NIParser::ProgContext* NIParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, NIParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == NIParser::VAR) {
      setState(44);
      var_specs();
    }
    setState(47);
    match(NIParser::BEGIN);
    setState(48);
    stat_seq();
    setState(49);
    match(NIParser::END);
    setState(50);
    match(NIParser::DOT);
    setState(51);
    match(NIParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

NIParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NIParser::Minus_expContext* NIParser::ExpContext::minus_exp() {
  return getRuleContext<NIParser::Minus_expContext>(0);
}

NIParser::Not_expContext* NIParser::ExpContext::not_exp() {
  return getRuleContext<NIParser::Not_expContext>(0);
}

NIParser::Binop_expContext* NIParser::ExpContext::binop_exp() {
  return getRuleContext<NIParser::Binop_expContext>(0);
}

NIParser::Bool_binop_expContext* NIParser::ExpContext::bool_binop_exp() {
  return getRuleContext<NIParser::Bool_binop_expContext>(0);
}

NIParser::TermContext* NIParser::ExpContext::term() {
  return getRuleContext<NIParser::TermContext>(0);
}


size_t NIParser::ExpContext::getRuleIndex() const {
  return NIParser::RuleExp;
}

void NIParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void NIParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


antlrcpp::Any NIParser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}

NIParser::ExpContext* NIParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 2, NIParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(58);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(53);
      minus_exp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(54);
      not_exp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(55);
      binop_exp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(56);
      bool_binop_exp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(57);
      term();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

NIParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NIParser::Par_expContext* NIParser::TermContext::par_exp() {
  return getRuleContext<NIParser::Par_expContext>(0);
}

NIParser::Int_termContext* NIParser::TermContext::int_term() {
  return getRuleContext<NIParser::Int_termContext>(0);
}

NIParser::Bool_termContext* NIParser::TermContext::bool_term() {
  return getRuleContext<NIParser::Bool_termContext>(0);
}

NIParser::Ident_termContext* NIParser::TermContext::ident_term() {
  return getRuleContext<NIParser::Ident_termContext>(0);
}


size_t NIParser::TermContext::getRuleIndex() const {
  return NIParser::RuleTerm;
}

void NIParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void NIParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


antlrcpp::Any NIParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

NIParser::TermContext* NIParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 4, NIParser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(64);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NIParser::LPAR: {
        enterOuterAlt(_localctx, 1);
        setState(60);
        par_exp();
        break;
      }

      case NIParser::Int: {
        enterOuterAlt(_localctx, 2);
        setState(61);
        int_term();
        break;
      }

      case NIParser::Bool: {
        enterOuterAlt(_localctx, 3);
        setState(62);
        bool_term();
        break;
      }

      case NIParser::Ident: {
        enterOuterAlt(_localctx, 4);
        setState(63);
        ident_term();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Int_termContext ------------------------------------------------------------------

NIParser::Int_termContext::Int_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Int_termContext::Int() {
  return getToken(NIParser::Int, 0);
}


size_t NIParser::Int_termContext::getRuleIndex() const {
  return NIParser::RuleInt_term;
}

void NIParser::Int_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt_term(this);
}

void NIParser::Int_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt_term(this);
}


antlrcpp::Any NIParser::Int_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitInt_term(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Int_termContext* NIParser::int_term() {
  Int_termContext *_localctx = _tracker.createInstance<Int_termContext>(_ctx, getState());
  enterRule(_localctx, 6, NIParser::RuleInt_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(NIParser::Int);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_termContext ------------------------------------------------------------------

NIParser::Bool_termContext::Bool_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Bool_termContext::Bool() {
  return getToken(NIParser::Bool, 0);
}


size_t NIParser::Bool_termContext::getRuleIndex() const {
  return NIParser::RuleBool_term;
}

void NIParser::Bool_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_term(this);
}

void NIParser::Bool_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_term(this);
}


antlrcpp::Any NIParser::Bool_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitBool_term(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Bool_termContext* NIParser::bool_term() {
  Bool_termContext *_localctx = _tracker.createInstance<Bool_termContext>(_ctx, getState());
  enterRule(_localctx, 8, NIParser::RuleBool_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(NIParser::Bool);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ident_termContext ------------------------------------------------------------------

NIParser::Ident_termContext::Ident_termContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Ident_termContext::Ident() {
  return getToken(NIParser::Ident, 0);
}


size_t NIParser::Ident_termContext::getRuleIndex() const {
  return NIParser::RuleIdent_term;
}

void NIParser::Ident_termContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdent_term(this);
}

void NIParser::Ident_termContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdent_term(this);
}


antlrcpp::Any NIParser::Ident_termContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitIdent_term(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Ident_termContext* NIParser::ident_term() {
  Ident_termContext *_localctx = _tracker.createInstance<Ident_termContext>(_ctx, getState());
  enterRule(_localctx, 10, NIParser::RuleIdent_term);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(NIParser::Ident);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Par_expContext ------------------------------------------------------------------

NIParser::Par_expContext::Par_expContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Par_expContext::LPAR() {
  return getToken(NIParser::LPAR, 0);
}

NIParser::ExpContext* NIParser::Par_expContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::Par_expContext::RPAR() {
  return getToken(NIParser::RPAR, 0);
}


size_t NIParser::Par_expContext::getRuleIndex() const {
  return NIParser::RulePar_exp;
}

void NIParser::Par_expContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPar_exp(this);
}

void NIParser::Par_expContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPar_exp(this);
}


antlrcpp::Any NIParser::Par_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitPar_exp(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Par_expContext* NIParser::par_exp() {
  Par_expContext *_localctx = _tracker.createInstance<Par_expContext>(_ctx, getState());
  enterRule(_localctx, 12, NIParser::RulePar_exp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(NIParser::LPAR);
    setState(73);
    exp();
    setState(74);
    match(NIParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Not_expContext ------------------------------------------------------------------

NIParser::Not_expContext::Not_expContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Not_expContext::NOT() {
  return getToken(NIParser::NOT, 0);
}

NIParser::ExpContext* NIParser::Not_expContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}


size_t NIParser::Not_expContext::getRuleIndex() const {
  return NIParser::RuleNot_exp;
}

void NIParser::Not_expContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot_exp(this);
}

void NIParser::Not_expContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot_exp(this);
}


antlrcpp::Any NIParser::Not_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitNot_exp(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Not_expContext* NIParser::not_exp() {
  Not_expContext *_localctx = _tracker.createInstance<Not_expContext>(_ctx, getState());
  enterRule(_localctx, 14, NIParser::RuleNot_exp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    match(NIParser::NOT);
    setState(77);
    exp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Minus_expContext ------------------------------------------------------------------

NIParser::Minus_expContext::Minus_expContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Minus_expContext::MINUS() {
  return getToken(NIParser::MINUS, 0);
}

NIParser::ExpContext* NIParser::Minus_expContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}


size_t NIParser::Minus_expContext::getRuleIndex() const {
  return NIParser::RuleMinus_exp;
}

void NIParser::Minus_expContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMinus_exp(this);
}

void NIParser::Minus_expContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMinus_exp(this);
}


antlrcpp::Any NIParser::Minus_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitMinus_exp(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Minus_expContext* NIParser::minus_exp() {
  Minus_expContext *_localctx = _tracker.createInstance<Minus_expContext>(_ctx, getState());
  enterRule(_localctx, 16, NIParser::RuleMinus_exp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(NIParser::MINUS);
    setState(80);
    exp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binop_expContext ------------------------------------------------------------------

NIParser::Binop_expContext::Binop_expContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NIParser::TermContext* NIParser::Binop_expContext::term() {
  return getRuleContext<NIParser::TermContext>(0);
}

NIParser::ExpContext* NIParser::Binop_expContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::Binop_expContext::TIMES() {
  return getToken(NIParser::TIMES, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::DIV() {
  return getToken(NIParser::DIV, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::PLUS() {
  return getToken(NIParser::PLUS, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::MINUS() {
  return getToken(NIParser::MINUS, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::EQ() {
  return getToken(NIParser::EQ, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::NEQ() {
  return getToken(NIParser::NEQ, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::LEQ() {
  return getToken(NIParser::LEQ, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::GEQ() {
  return getToken(NIParser::GEQ, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::GT() {
  return getToken(NIParser::GT, 0);
}

tree::TerminalNode* NIParser::Binop_expContext::LT() {
  return getToken(NIParser::LT, 0);
}


size_t NIParser::Binop_expContext::getRuleIndex() const {
  return NIParser::RuleBinop_exp;
}

void NIParser::Binop_expContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinop_exp(this);
}

void NIParser::Binop_expContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinop_exp(this);
}


antlrcpp::Any NIParser::Binop_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitBinop_exp(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Binop_expContext* NIParser::binop_exp() {
  Binop_expContext *_localctx = _tracker.createInstance<Binop_expContext>(_ctx, getState());
  enterRule(_localctx, 18, NIParser::RuleBinop_exp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(94);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(82);
      term();
      setState(83);
      _la = _input->LA(1);
      if (!(_la == NIParser::TIMES

      || _la == NIParser::DIV)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(84);
      exp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      term();
      setState(87);
      _la = _input->LA(1);
      if (!(_la == NIParser::PLUS

      || _la == NIParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(88);
      exp();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(90);
      term();
      setState(91);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << NIParser::LT)
        | (1ULL << NIParser::GT)
        | (1ULL << NIParser::LEQ)
        | (1ULL << NIParser::GEQ)
        | (1ULL << NIParser::EQ)
        | (1ULL << NIParser::NEQ))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(92);
      exp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_binop_expContext ------------------------------------------------------------------

NIParser::Bool_binop_expContext::Bool_binop_expContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NIParser::TermContext* NIParser::Bool_binop_expContext::term() {
  return getRuleContext<NIParser::TermContext>(0);
}

tree::TerminalNode* NIParser::Bool_binop_expContext::AND() {
  return getToken(NIParser::AND, 0);
}

NIParser::ExpContext* NIParser::Bool_binop_expContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::Bool_binop_expContext::OR() {
  return getToken(NIParser::OR, 0);
}


size_t NIParser::Bool_binop_expContext::getRuleIndex() const {
  return NIParser::RuleBool_binop_exp;
}

void NIParser::Bool_binop_expContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_binop_exp(this);
}

void NIParser::Bool_binop_expContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_binop_exp(this);
}


antlrcpp::Any NIParser::Bool_binop_expContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitBool_binop_exp(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Bool_binop_expContext* NIParser::bool_binop_exp() {
  Bool_binop_expContext *_localctx = _tracker.createInstance<Bool_binop_expContext>(_ctx, getState());
  enterRule(_localctx, 20, NIParser::RuleBool_binop_exp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(96);
      term();
      setState(97);
      match(NIParser::AND);
      setState(98);
      exp();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      term();
      setState(101);
      match(NIParser::OR);
      setState(102);
      exp();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

NIParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NIParser::AssignmentContext* NIParser::StatContext::assignment() {
  return getRuleContext<NIParser::AssignmentContext>(0);
}

NIParser::If_then_elseContext* NIParser::StatContext::if_then_else() {
  return getRuleContext<NIParser::If_then_elseContext>(0);
}

NIParser::If_thenContext* NIParser::StatContext::if_then() {
  return getRuleContext<NIParser::If_thenContext>(0);
}

NIParser::While_loopContext* NIParser::StatContext::while_loop() {
  return getRuleContext<NIParser::While_loopContext>(0);
}

NIParser::PrintContext* NIParser::StatContext::print() {
  return getRuleContext<NIParser::PrintContext>(0);
}


size_t NIParser::StatContext::getRuleIndex() const {
  return NIParser::RuleStat;
}

void NIParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void NIParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
}


antlrcpp::Any NIParser::StatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitStat(this);
  else
    return visitor->visitChildren(this);
}

NIParser::StatContext* NIParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 22, NIParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(106);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(107);
      if_then_else();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(108);
      if_then();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(109);
      while_loop();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(110);
      print();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

NIParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::AssignmentContext::Ident() {
  return getToken(NIParser::Ident, 0);
}

tree::TerminalNode* NIParser::AssignmentContext::ASSIGN() {
  return getToken(NIParser::ASSIGN, 0);
}

NIParser::ExpContext* NIParser::AssignmentContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}


size_t NIParser::AssignmentContext::getRuleIndex() const {
  return NIParser::RuleAssignment;
}

void NIParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void NIParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


antlrcpp::Any NIParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

NIParser::AssignmentContext* NIParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 24, NIParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    match(NIParser::Ident);
    setState(114);
    match(NIParser::ASSIGN);
    setState(115);
    exp();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_thenContext ------------------------------------------------------------------

NIParser::If_thenContext::If_thenContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::If_thenContext::IF() {
  return getToken(NIParser::IF, 0);
}

NIParser::ExpContext* NIParser::If_thenContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::If_thenContext::THEN() {
  return getToken(NIParser::THEN, 0);
}

NIParser::Stat_blockContext* NIParser::If_thenContext::stat_block() {
  return getRuleContext<NIParser::Stat_blockContext>(0);
}


size_t NIParser::If_thenContext::getRuleIndex() const {
  return NIParser::RuleIf_then;
}

void NIParser::If_thenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_then(this);
}

void NIParser::If_thenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_then(this);
}


antlrcpp::Any NIParser::If_thenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitIf_then(this);
  else
    return visitor->visitChildren(this);
}

NIParser::If_thenContext* NIParser::if_then() {
  If_thenContext *_localctx = _tracker.createInstance<If_thenContext>(_ctx, getState());
  enterRule(_localctx, 26, NIParser::RuleIf_then);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(NIParser::IF);
    setState(118);
    exp();
    setState(119);
    match(NIParser::THEN);
    setState(120);
    stat_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_then_elseContext ------------------------------------------------------------------

NIParser::If_then_elseContext::If_then_elseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::If_then_elseContext::IF() {
  return getToken(NIParser::IF, 0);
}

NIParser::ExpContext* NIParser::If_then_elseContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::If_then_elseContext::THEN() {
  return getToken(NIParser::THEN, 0);
}

std::vector<NIParser::Stat_blockContext *> NIParser::If_then_elseContext::stat_block() {
  return getRuleContexts<NIParser::Stat_blockContext>();
}

NIParser::Stat_blockContext* NIParser::If_then_elseContext::stat_block(size_t i) {
  return getRuleContext<NIParser::Stat_blockContext>(i);
}

tree::TerminalNode* NIParser::If_then_elseContext::ELSE() {
  return getToken(NIParser::ELSE, 0);
}


size_t NIParser::If_then_elseContext::getRuleIndex() const {
  return NIParser::RuleIf_then_else;
}

void NIParser::If_then_elseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_then_else(this);
}

void NIParser::If_then_elseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_then_else(this);
}


antlrcpp::Any NIParser::If_then_elseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitIf_then_else(this);
  else
    return visitor->visitChildren(this);
}

NIParser::If_then_elseContext* NIParser::if_then_else() {
  If_then_elseContext *_localctx = _tracker.createInstance<If_then_elseContext>(_ctx, getState());
  enterRule(_localctx, 28, NIParser::RuleIf_then_else);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(NIParser::IF);
    setState(123);
    exp();
    setState(124);
    match(NIParser::THEN);
    setState(125);
    stat_block();
    setState(126);
    match(NIParser::ELSE);
    setState(127);
    stat_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_loopContext ------------------------------------------------------------------

NIParser::While_loopContext::While_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::While_loopContext::WHILE() {
  return getToken(NIParser::WHILE, 0);
}

NIParser::ExpContext* NIParser::While_loopContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::While_loopContext::DO() {
  return getToken(NIParser::DO, 0);
}

NIParser::Stat_blockContext* NIParser::While_loopContext::stat_block() {
  return getRuleContext<NIParser::Stat_blockContext>(0);
}


size_t NIParser::While_loopContext::getRuleIndex() const {
  return NIParser::RuleWhile_loop;
}

void NIParser::While_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_loop(this);
}

void NIParser::While_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_loop(this);
}


antlrcpp::Any NIParser::While_loopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitWhile_loop(this);
  else
    return visitor->visitChildren(this);
}

NIParser::While_loopContext* NIParser::while_loop() {
  While_loopContext *_localctx = _tracker.createInstance<While_loopContext>(_ctx, getState());
  enterRule(_localctx, 30, NIParser::RuleWhile_loop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    match(NIParser::WHILE);
    setState(130);
    exp();
    setState(131);
    match(NIParser::DO);
    setState(132);
    stat_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

NIParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::PrintContext::PRINT() {
  return getToken(NIParser::PRINT, 0);
}

tree::TerminalNode* NIParser::PrintContext::LPAR() {
  return getToken(NIParser::LPAR, 0);
}

NIParser::ExpContext* NIParser::PrintContext::exp() {
  return getRuleContext<NIParser::ExpContext>(0);
}

tree::TerminalNode* NIParser::PrintContext::RPAR() {
  return getToken(NIParser::RPAR, 0);
}


size_t NIParser::PrintContext::getRuleIndex() const {
  return NIParser::RulePrint;
}

void NIParser::PrintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint(this);
}

void NIParser::PrintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint(this);
}


antlrcpp::Any NIParser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}

NIParser::PrintContext* NIParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 32, NIParser::RulePrint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(NIParser::PRINT);
    setState(135);
    match(NIParser::LPAR);
    setState(136);
    exp();
    setState(137);
    match(NIParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

NIParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Var_declContext::Ident() {
  return getToken(NIParser::Ident, 0);
}

tree::TerminalNode* NIParser::Var_declContext::COLON() {
  return getToken(NIParser::COLON, 0);
}

tree::TerminalNode* NIParser::Var_declContext::Typename() {
  return getToken(NIParser::Typename, 0);
}


size_t NIParser::Var_declContext::getRuleIndex() const {
  return NIParser::RuleVar_decl;
}

void NIParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}

void NIParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}


antlrcpp::Any NIParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Var_declContext* NIParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 34, NIParser::RuleVar_decl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(NIParser::Ident);
    setState(140);
    match(NIParser::COLON);
    setState(141);
    match(NIParser::Typename);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_specsContext ------------------------------------------------------------------

NIParser::Var_specsContext::Var_specsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Var_specsContext::VAR() {
  return getToken(NIParser::VAR, 0);
}

std::vector<NIParser::Var_declContext *> NIParser::Var_specsContext::var_decl() {
  return getRuleContexts<NIParser::Var_declContext>();
}

NIParser::Var_declContext* NIParser::Var_specsContext::var_decl(size_t i) {
  return getRuleContext<NIParser::Var_declContext>(i);
}

std::vector<tree::TerminalNode *> NIParser::Var_specsContext::SEMI() {
  return getTokens(NIParser::SEMI);
}

tree::TerminalNode* NIParser::Var_specsContext::SEMI(size_t i) {
  return getToken(NIParser::SEMI, i);
}


size_t NIParser::Var_specsContext::getRuleIndex() const {
  return NIParser::RuleVar_specs;
}

void NIParser::Var_specsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_specs(this);
}

void NIParser::Var_specsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_specs(this);
}


antlrcpp::Any NIParser::Var_specsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitVar_specs(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Var_specsContext* NIParser::var_specs() {
  Var_specsContext *_localctx = _tracker.createInstance<Var_specsContext>(_ctx, getState());
  enterRule(_localctx, 36, NIParser::RuleVar_specs);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
    match(NIParser::VAR);
    setState(147); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(144);
      var_decl();
      setState(145);
      match(NIParser::SEMI);
      setState(149); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == NIParser::Ident);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_seqContext ------------------------------------------------------------------

NIParser::Stat_seqContext::Stat_seqContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<NIParser::StatContext *> NIParser::Stat_seqContext::stat() {
  return getRuleContexts<NIParser::StatContext>();
}

NIParser::StatContext* NIParser::Stat_seqContext::stat(size_t i) {
  return getRuleContext<NIParser::StatContext>(i);
}

std::vector<tree::TerminalNode *> NIParser::Stat_seqContext::SEMI() {
  return getTokens(NIParser::SEMI);
}

tree::TerminalNode* NIParser::Stat_seqContext::SEMI(size_t i) {
  return getToken(NIParser::SEMI, i);
}


size_t NIParser::Stat_seqContext::getRuleIndex() const {
  return NIParser::RuleStat_seq;
}

void NIParser::Stat_seqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_seq(this);
}

void NIParser::Stat_seqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_seq(this);
}


antlrcpp::Any NIParser::Stat_seqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitStat_seq(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Stat_seqContext* NIParser::stat_seq() {
  Stat_seqContext *_localctx = _tracker.createInstance<Stat_seqContext>(_ctx, getState());
  enterRule(_localctx, 38, NIParser::RuleStat_seq);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    stat();
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == NIParser::SEMI) {
      setState(152);
      match(NIParser::SEMI);
      setState(153);
      stat();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Stat_blockContext ------------------------------------------------------------------

NIParser::Stat_blockContext::Stat_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

NIParser::StatContext* NIParser::Stat_blockContext::stat() {
  return getRuleContext<NIParser::StatContext>(0);
}

NIParser::Begin_endContext* NIParser::Stat_blockContext::begin_end() {
  return getRuleContext<NIParser::Begin_endContext>(0);
}


size_t NIParser::Stat_blockContext::getRuleIndex() const {
  return NIParser::RuleStat_block;
}

void NIParser::Stat_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat_block(this);
}

void NIParser::Stat_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat_block(this);
}


antlrcpp::Any NIParser::Stat_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitStat_block(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Stat_blockContext* NIParser::stat_block() {
  Stat_blockContext *_localctx = _tracker.createInstance<Stat_blockContext>(_ctx, getState());
  enterRule(_localctx, 40, NIParser::RuleStat_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case NIParser::IF:
      case NIParser::WHILE:
      case NIParser::PRINT:
      case NIParser::Ident: {
        enterOuterAlt(_localctx, 1);
        setState(159);
        stat();
        break;
      }

      case NIParser::BEGIN: {
        enterOuterAlt(_localctx, 2);
        setState(160);
        begin_end();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Begin_endContext ------------------------------------------------------------------

NIParser::Begin_endContext::Begin_endContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* NIParser::Begin_endContext::BEGIN() {
  return getToken(NIParser::BEGIN, 0);
}

NIParser::Stat_seqContext* NIParser::Begin_endContext::stat_seq() {
  return getRuleContext<NIParser::Stat_seqContext>(0);
}

tree::TerminalNode* NIParser::Begin_endContext::END() {
  return getToken(NIParser::END, 0);
}


size_t NIParser::Begin_endContext::getRuleIndex() const {
  return NIParser::RuleBegin_end;
}

void NIParser::Begin_endContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBegin_end(this);
}

void NIParser::Begin_endContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<NIParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBegin_end(this);
}


antlrcpp::Any NIParser::Begin_endContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<NIParserVisitor*>(visitor))
    return parserVisitor->visitBegin_end(this);
  else
    return visitor->visitChildren(this);
}

NIParser::Begin_endContext* NIParser::begin_end() {
  Begin_endContext *_localctx = _tracker.createInstance<Begin_endContext>(_ctx, getState());
  enterRule(_localctx, 42, NIParser::RuleBegin_end);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(NIParser::BEGIN);
    setState(164);
    stat_seq();
    setState(165);
    match(NIParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> NIParser::_decisionToDFA;
atn::PredictionContextCache NIParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN NIParser::_atn;
std::vector<uint16_t> NIParser::_serializedATN;

std::vector<std::string> NIParser::_ruleNames = {
  "prog", "exp", "term", "int_term", "bool_term", "ident_term", "par_exp", 
  "not_exp", "minus_exp", "binop_exp", "bool_binop_exp", "stat", "assignment", 
  "if_then", "if_then_else", "while_loop", "print", "var_decl", "var_specs", 
  "stat_seq", "stat_block", "begin_end"
};

std::vector<std::string> NIParser::_literalNames = {
  "", "", "", "", "'<'", "'>'", "'<='", "'>='", "'='", "'<>'", "'and'", 
  "'or'", "'not'", "'true'", "'false'", "':='", "','", "'.'", "':'", "';'", 
  "'+'", "'-'", "'*'", "'div'", "'('", "')'", "'var'", "'boolean'", "'integer'", 
  "'if'", "'then'", "'else'", "'while'", "'do'", "'begin'", "'end'", "'print'", 
  "", "", "", "", "'_'"
};

std::vector<std::string> NIParser::_symbolicNames = {
  "", "Int", "Bool", "Typename", "LT", "GT", "LEQ", "GEQ", "EQ", "NEQ", 
  "AND", "OR", "NOT", "TRUE", "FALSE", "ASSIGN", "COMMA", "DOT", "COLON", 
  "SEMI", "PLUS", "MINUS", "TIMES", "DIV", "LPAR", "RPAR", "VAR", "BOOLEAN", 
  "INTEGER", "IF", "THEN", "ELSE", "WHILE", "DO", "BEGIN", "END", "PRINT", 
  "Ident", "WS", "DIGIT", "LETTER", "UNDER"
};

dfa::Vocabulary NIParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> NIParser::_tokenNames;

NIParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2b, 0xaa, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x5, 0x2, 
    0x30, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x3d, 
    0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x43, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x61, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x6b, 0xa, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x72, 0xa, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x6, 0x14, 0x96, 0xa, 0x14, 0xd, 0x14, 0xe, 0x14, 0x97, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x9d, 0xa, 0x15, 0xc, 0x15, 0xe, 
    0x15, 0xa0, 0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xa4, 0xa, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x2, 0x2, 0x18, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 0x5, 0x3, 
    0x2, 0x18, 0x19, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x6, 0xb, 0x2, 0xa5, 
    0x2, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x44, 0x3, 0x2, 0x2, 0x2, 0xa, 0x46, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x48, 0x3, 0x2, 0x2, 0x2, 0xe, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x12, 0x51, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x18, 0x71, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x73, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x20, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0x88, 0x3, 0x2, 0x2, 0x2, 0x24, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x91, 0x3, 0x2, 0x2, 0x2, 0x28, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0x30, 0x5, 0x26, 0x14, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x30, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 
    0x24, 0x2, 0x2, 0x32, 0x33, 0x5, 0x28, 0x15, 0x2, 0x33, 0x34, 0x7, 0x25, 
    0x2, 0x2, 0x34, 0x35, 0x7, 0x13, 0x2, 0x2, 0x35, 0x36, 0x7, 0x2, 0x2, 
    0x3, 0x36, 0x3, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3d, 0x5, 0x12, 0xa, 0x2, 
    0x38, 0x3d, 0x5, 0x10, 0x9, 0x2, 0x39, 0x3d, 0x5, 0x14, 0xb, 0x2, 0x3a, 
    0x3d, 0x5, 0x16, 0xc, 0x2, 0x3b, 0x3d, 0x5, 0x6, 0x4, 0x2, 0x3c, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x43, 0x5, 0xe, 0x8, 
    0x2, 0x3f, 0x43, 0x5, 0x8, 0x5, 0x2, 0x40, 0x43, 0x5, 0xa, 0x6, 0x2, 
    0x41, 0x43, 0x5, 0xc, 0x7, 0x2, 0x42, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 
    0x3, 0x2, 0x2, 0x45, 0x9, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x4, 
    0x2, 0x2, 0x47, 0xb, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x27, 0x2, 
    0x2, 0x49, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x1a, 0x2, 0x2, 
    0x4b, 0x4c, 0x5, 0x4, 0x3, 0x2, 0x4c, 0x4d, 0x7, 0x1b, 0x2, 0x2, 0x4d, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0xe, 0x2, 0x2, 0x4f, 0x50, 
    0x5, 0x4, 0x3, 0x2, 0x50, 0x11, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 
    0x17, 0x2, 0x2, 0x52, 0x53, 0x5, 0x4, 0x3, 0x2, 0x53, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x55, 0x5, 0x6, 0x4, 0x2, 0x55, 0x56, 0x9, 0x2, 0x2, 
    0x2, 0x56, 0x57, 0x5, 0x4, 0x3, 0x2, 0x57, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x59, 0x5, 0x6, 0x4, 0x2, 0x59, 0x5a, 0x9, 0x3, 0x2, 0x2, 0x5a, 
    0x5b, 0x5, 0x4, 0x3, 0x2, 0x5b, 0x61, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 
    0x5, 0x6, 0x4, 0x2, 0x5d, 0x5e, 0x9, 0x4, 0x2, 0x2, 0x5e, 0x5f, 0x5, 
    0x4, 0x3, 0x2, 0x5f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x60, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x58, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x15, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x5, 0x6, 0x4, 0x2, 
    0x63, 0x64, 0x7, 0xc, 0x2, 0x2, 0x64, 0x65, 0x5, 0x4, 0x3, 0x2, 0x65, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x5, 0x6, 0x4, 0x2, 0x67, 0x68, 
    0x7, 0xd, 0x2, 0x2, 0x68, 0x69, 0x5, 0x4, 0x3, 0x2, 0x69, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x62, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x72, 0x5, 0x1a, 0xe, 
    0x2, 0x6d, 0x72, 0x5, 0x1e, 0x10, 0x2, 0x6e, 0x72, 0x5, 0x1c, 0xf, 0x2, 
    0x6f, 0x72, 0x5, 0x20, 0x11, 0x2, 0x70, 0x72, 0x5, 0x22, 0x12, 0x2, 
    0x71, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x19, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 
    0x27, 0x2, 0x2, 0x74, 0x75, 0x7, 0x11, 0x2, 0x2, 0x75, 0x76, 0x5, 0x4, 
    0x3, 0x2, 0x76, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0x1f, 0x2, 
    0x2, 0x78, 0x79, 0x5, 0x4, 0x3, 0x2, 0x79, 0x7a, 0x7, 0x20, 0x2, 0x2, 
    0x7a, 0x7b, 0x5, 0x2a, 0x16, 0x2, 0x7b, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7d, 0x7, 0x1f, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x4, 0x3, 0x2, 0x7e, 0x7f, 
    0x7, 0x20, 0x2, 0x2, 0x7f, 0x80, 0x5, 0x2a, 0x16, 0x2, 0x80, 0x81, 0x7, 
    0x21, 0x2, 0x2, 0x81, 0x82, 0x5, 0x2a, 0x16, 0x2, 0x82, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x7, 0x22, 0x2, 0x2, 0x84, 0x85, 0x5, 0x4, 0x3, 
    0x2, 0x85, 0x86, 0x7, 0x23, 0x2, 0x2, 0x86, 0x87, 0x5, 0x2a, 0x16, 0x2, 
    0x87, 0x21, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x26, 0x2, 0x2, 0x89, 
    0x8a, 0x7, 0x1a, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x4, 0x3, 0x2, 0x8b, 0x8c, 
    0x7, 0x1b, 0x2, 0x2, 0x8c, 0x23, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 
    0x27, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x14, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x5, 
    0x2, 0x2, 0x90, 0x25, 0x3, 0x2, 0x2, 0x2, 0x91, 0x95, 0x7, 0x1c, 0x2, 
    0x2, 0x92, 0x93, 0x5, 0x24, 0x13, 0x2, 0x93, 0x94, 0x7, 0x15, 0x2, 0x2, 
    0x94, 0x96, 0x3, 0x2, 0x2, 0x2, 0x95, 0x92, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x27, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9e, 0x5, 
    0x18, 0xd, 0x2, 0x9a, 0x9b, 0x7, 0x15, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x18, 
    0xd, 0x2, 0x9c, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0x29, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 
    0xa4, 0x5, 0x18, 0xd, 0x2, 0xa2, 0xa4, 0x5, 0x2c, 0x17, 0x2, 0xa3, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x24, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x28, 
    0x15, 0x2, 0xa7, 0xa8, 0x7, 0x25, 0x2, 0x2, 0xa8, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0xb, 0x2f, 0x3c, 0x42, 0x60, 0x6a, 0x71, 0x97, 0x9e, 0xa3, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

NIParser::Initializer NIParser::_init;
