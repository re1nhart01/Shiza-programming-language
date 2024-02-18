#include <string>


namespace shiza::errors {
    const std::string LEXER_UNEXPECTED_TOKEN = "LexerError: Unexpected token on position: ";
    const std::string LEXER_PACKAGE_ERROR = "LexerError: Package keyword should be first in string";
}