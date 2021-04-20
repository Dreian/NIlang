#include "antlr4-runtime.h"

using namespace antlr4;

class NIParserErrorListener : public antlr4::BaseErrorListener {
private:
  bool &error_bit;
public:
  NIParserErrorListener(bool&);
  virtual void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line, size_t charPositionInLine,
                           const std::string &msg, std::exception_ptr e) override;
};