
// Generated from grammars/NILexer.g4 by ANTLR 4.9

#pragma once


#include "antlr4-runtime.h"




class  NILexer : public antlr4::Lexer {
public:
  enum {
    Int = 1, Bool = 2, Typename = 3, LT = 4, GT = 5, LEQ = 6, GEQ = 7, EQ = 8, 
    NEQ = 9, AND = 10, OR = 11, NOT = 12, TRUE = 13, FALSE = 14, ASSIGN = 15, 
    COMMA = 16, DOT = 17, COLON = 18, SEMI = 19, PLUS = 20, MINUS = 21, 
    TIMES = 22, DIV = 23, LPAR = 24, RPAR = 25, VAR = 26, BOOLEAN = 27, 
    INTEGER = 28, IF = 29, THEN = 30, ELSE = 31, WHILE = 32, DO = 33, BEGIN = 34, 
    END = 35, PRINT = 36, Ident = 37, WS = 38, DIGIT = 39, LETTER = 40, 
    UNDER = 41
  };

  explicit NILexer(antlr4::CharStream *input);
  ~NILexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

