#include "ast.h"
#include "helpers.cc"
#include "global.cc"
#include "keywords.cc"
#include "debugging.cc";
#include <cstdio>
#include <functional>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <typeindex>
#include <vector>
#include "string.h"

#define __DEV__ // __PROD__ || __DEV__ || __DEVOPUS__ || __PUMB__

using namespace std;
using namespace shiza::tokens;
namespace shiza {
    // lib for unicode will be called - unidroch

    class ArgParser {
    public:
      void argumentCase();
    private:

    };


    struct __INHERIT_NODE__ {
      std::string name;
      shiza::ast::ASTNode* value;
    };



    class Token {
      int col;
      int row;
      ast::TokenType __TOKEN_TYPE;
      std::string __TOKEN_VALUE;
      Token(int col, int row, ast::TokenType type, const std::string value) {
        this->__TOKEN_TYPE = type;
        this->__TOKEN_VALUE = value;
        this->col = col;
        this->row = row;
      }
    };

    class Lexer {
    public:
        std::vector<__INHERIT_NODE__*> tokenList;
        std::basic_ifstream<char>* stream;
        std::string currentFileName;
        int col;
        int row;
        bool isStringOpened;
        bool isBracketOpened;
        Lexer() {
            this->stream = { nullptr };
            this->currentFileName = "main.bmx";
            this->tokenList = std::vector<__INHERIT_NODE__*>{ nullptr };
            this->row = 0;
            this->col = 0;
            this->isStringOpened = false;
            this->isBracketOpened = false;
        }
        void runLexicalAnalysis(std::ifstream& fileStream);
        void lookingForNode(std::string line);
    };


    class Linker {

    };

    class LexerFunc {
    public:
        virtual ~LexerFunc() = delete;
        static __INHERIT_NODE__* lex_package_node(vector<std::string> currLine);
        static __INHERIT_NODE__* lex_define_node(vector<std::string> currLine);
        static __INHERIT_NODE__* lex_assignment_node(vector<std::string> currLine);
        static __INHERIT_NODE__* lex_func_node(vector<std::string> currLine, std::basic_ifstream<char>* if_stream_current);
        static __INHERIT_NODE__* lex_log_node(vector<std::string> currLine);
    };

    __INHERIT_NODE__* LexerFunc::lex_package_node(vector<std::string> currLine) {
        for (std::string line_node : currLine) {

        }
        return nullptr;
    }

    __INHERIT_NODE__* LexerFunc::lex_define_node(vector<std::string> currLine) {
        for (std::string line_node : currLine) {

        }
        return nullptr;
    }

    __INHERIT_NODE__* LexerFunc::lex_assignment_node(vector<std::string> currLine) {
        for (std::string line_node : currLine) {

        }
        return nullptr;
    }

    __INHERIT_NODE__* LexerFunc::lex_func_node(vector<std::string> currLine, std::basic_ifstream<char>* if_stream_current) {
        return nullptr;
    }

    __INHERIT_NODE__* LexerFunc::lex_log_node(vector<std::string> currLine) {
        for (std::string line_node : currLine) {

        }
        return nullptr;
    }


    void Lexer::runLexicalAnalysis(std::ifstream& fileStream) {
      if (fileStream.is_open()) {
        std::string currentLine;
        this->stream = &fileStream;
        while (fileStream.good()) {
          getline(fileStream, currentLine);
          unsigned long sizeOfLine = currentLine.size();

          //to explicit empty lines
          Lexer::row++;

          if (sizeOfLine != 0) {
            shiza::helpers::trim(currentLine);
            this->lookingForNode(currentLine);
          }
        }
      }
      fileStream.close();
      this->stream = { nullptr };
    }

//void Lexer::lookingForNode(std::string line, std::ifstream& fileStream) const {
// std::string curr = line;
// int startPos = 0;
// int endPos = 0;
// bool isStringOpened = false;
// shiza::helpers::trim(curr);
// while(endPos < line.length()) {
//   endPos++;
//   std::string substrOfLine = line.substr(startPos, endPos);
//   cout << substrOfLine << endl;
//
//   if (substrOfLine == DEFINE_KEYWORD) {
//   } else if (substrOfLine == PACKAGE_KEYWORD) {
//   } else if (substrOfLine == FUNCTION_KEYWORD) {
//   } else if (substrOfLine == LOGGIN_KEYWORD) {
//   } else if (substrOfLine == LEFT_BRACKET) {
//   } else if (substrOfLine == RIGHT_BRACKET) {
//   } else if (substrOfLine == LEFT_PARENTHESIS) {
//   } else if (substrOfLine == RIGHT_PARENTHESIS) {
//   } else if (substrOfLine == SEMICOLON) {
//   } else if (substrOfLine == ASSIGNMENT) {
//   } else if (substrOfLine == STRING_LITERAL) {
//     isStringOpened = !isStringOpened;
//   } else if (substrOfLine == MULTILINE_STRING_LITERAL) {
//     isStringOpened = !isStringOpened;
//   } else {
//
//   }
//  if (!isStringOpened) {
//    if (line[endPos] != ' ' && endPos < line.length()) {
//
//    }
//  }
//
// }
//};

    void Lexer::lookingForNode(std::string line) {
         std::string curr = line;
         Lexer::col = 0;

         if (!this->isStringOpened) {
           shiza::helpers::trim(curr);
         }
         // hint: this vector contains separated string with spaces like: "an 100 apples" ["an", " ", "100", " ", "apples"]
         vector<std::string> current_line_by_nodes = shiza::helpers::split_with_spaces(curr);
         ss_print_vector(current_line_by_nodes);
         for (std::string node : current_line_by_nodes) {
            if (!this->isStringOpened) {
              if (node != " " && node != ";") {
                  Lexer::col+= node.size();
                  //hint: comment section ->
                  if (shiza::helpers::compare_keywords_multiple(node, vector<std::string>{
                          shiza::tokens::COMMENT_SINGLE_LINE,
                          shiza::tokens::COMMENT_MULTILINE_MIDDLE,
                          shiza::tokens::COMMENT_MULTILINE_START,
                  })) {
                      cout << shiza::tokens::COMMENT_SINGLE_LINE << endl;
                      continue;
                  } else if (shiza::helpers::compare_keywords(node, shiza::tokens::PACKAGE_KEYWORD)) {
                      this->tokenList.push_back(LexerFunc::lex_package_node(current_line_by_nodes));
                      cout << shiza::tokens::PACKAGE_KEYWORD << endl;
                  } else if (shiza::helpers::compare_keywords(node, shiza::tokens::FUNCTION_KEYWORD)) {
                      this->tokenList.push_back(LexerFunc::lex_func_node(current_line_by_nodes, this->stream));
                      this->isBracketOpened = true;
                      cout << shiza::tokens::FUNCTION_KEYWORD << endl;
                  } else if (shiza::helpers::compare_keywords(node, shiza::tokens::DEFINE_KEYWORD)) {
                      this->tokenList.push_back(LexerFunc::lex_define_node(current_line_by_nodes));
                      cout << shiza::tokens::DEFINE_KEYWORD << endl;
                  } else if (shiza::helpers::compare_keywords(node, shiza::tokens::ASSIGNMENT)) {
                      this->tokenList.push_back(LexerFunc::lex_assignment_node(current_line_by_nodes));
                      cout << shiza::tokens::ASSIGNMENT << endl;
                  } else if (shiza::helpers::compare_keywords(node, shiza::tokens::LOGGIN_KEYWORD)) {
                      this->tokenList.push_back(LexerFunc::lex_log_node(current_line_by_nodes));
                      cout << shiza::tokens::LOGGIN_KEYWORD << endl;
                  }
              } else {
                  Lexer::col++;
              }
            } else {
              ss_todo();
            }
         }
         cout << Lexer::row << " " << Lexer::col << endl;
    };

    __INHERIT_NODE__ tester() {
      return __INHERIT_NODE__{ "ParamNode", new shiza::ast::ParamNode("sasd", shiza::ast::INTEGER_TYPE, new shiza::ast::ASTNode()) };
    };



    class Parser {
    public:
        void run_parser(const vector<__INHERIT_NODE__> token_list);
    };

    class Error {
    protected:
      std::string errorType;
    public:
      bool hasError;
      std::string stackTrace;
      Error(const std::string stackTrace) {
        this->stackTrace = stackTrace;
        this->hasError = sizeof(stackTrace) != 0;
        this->errorType = "kernel_error!";
      }
    };

    class LexicalError final : public Error {
      LexicalError(const std::string stackTrace) : Error(stackTrace) {
        this->stackTrace = stackTrace;
        this->hasError = sizeof(stackTrace) != 0;
        this->errorType = "lexer_error!";
      }
    };

    class FS {
    public:
      std::ifstream read(const std::string filePath);
      Error write(const std::string content);
      std::ifstream bulkRead(const std::string initialFilePath);
    };

    std::ifstream FS::read(const std::string filePath) {
      std::ifstream OPENED_FILE;
      OPENED_FILE.open(filePath);
      return OPENED_FILE;
    }
}


    int main (int argc, char **argv) {
    #ifdef __DEV__
        ss_UNSAFE_clear_console();
        cout << ">>> SHIZA DEVELOPMENT MODE <<<" << endl;
    #ifdef __PLAYGROUND__
        shiza::debugging::run_test();
        return 0;
    #endif
    #endif

        shiza::FS fs;
        shiza::Lexer lexer;
        cout << ss_get_root_path() + TEST_FILE_PATH << endl;
        std::ifstream file = fs.read(ss_get_root_path() + TEST_FILE_PATH);
        lexer.runLexicalAnalysis(file);
        shiza::__INHERIT_NODE__ root = shiza::tester();
        cout << root.name << endl;
        shiza::ast::ParamNode* node = dynamic_cast<shiza::ast::ParamNode*>(root.value);
        cout << node->name << endl;
        return 0;
    }


