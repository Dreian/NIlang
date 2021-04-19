#include "ErrorListeners.h"

using namespace antlr4;

NIParserErrorListener::NIParserErrorListener(bool &error) : error_bit(error) {
  error_bit = false;
}

void NIParserErrorListener::syntaxError(Recognizer *recognizer, Token *offendingSymbol,
                                        size_t line, size_t charPositionInLine,
                                        const std::string &msg, std::exception_ptr e) {
  std::cerr << "Syntax error on line " << line << ", column " << charPositionInLine << ":" << std::endl
            << "  " << msg << std::endl;
  error_bit = true;
}