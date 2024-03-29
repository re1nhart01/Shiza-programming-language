#include <string>
#include <vector>

namespace shiza::tokens {
    const std::vector<std::string> RESERVED_SYMBOLS = { "!", "!!", "?", "??", "^", "|", "$", "$$", "*", "/", "&", "-", "%", "%%", "+", "**" };
    const std::string COMMENT_SINGLE_LINE = "$";
    const std::string COMMENT_MULTILINE_START = "$$";
    const std::string COMMENT_MULTILINE_MIDDLE = "*";
    const std::string DEFINE_KEYWORD = "define";
    const std::string PACKAGE_KEYWORD = "package";
    const std::string FUNCTION_KEYWORD = "do";
    const std::string LOGGIN_KEYWORD = "log";
    const std::string LEFT_BRACKET = "(";
    const std::string RIGHT_BRACKET = ")";
    const std::string LEFT_PARENTHESIS = "[";
    const std::string RIGHT_PARENTHESIS = "]";
    const std::string SEMICOLON = ";";
    const std::string ASSIGNMENT = "=";
    const std::string STRING_LITERAL = "\"";
    const std::string MULTILINE_STRING_LITERAL = "'";
    const std::string ENV_NODE = "#env-node";
    const std::string ENV_WEB = "#env-web";
}