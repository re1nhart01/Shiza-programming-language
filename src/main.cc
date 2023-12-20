#include "ast.h"
#include "helpers.cc"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

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


class Linker {

};

class Lexer {
public:
  std::vector<void*> tokenList;
  int col;
  int row;
  Lexer() {
    this->tokenList = std::vector<void*>{ 0 };
    this->row = 0;
    this->col = 0;
  }
  void runLexicalAnalysis(std::ifstream& fileStream);
  shiza::ast::ASTNode* lookingForNode(std::string line) const;
};

void Lexer::runLexicalAnalysis(std::ifstream& fileStream) {
  //  cout << fileStream.is_open();
  if (fileStream.is_open()) {
    std::string currentLine;
    int localCol = 0;
    int localRow = 0;
    while (fileStream.good()) {
      getline(fileStream, currentLine);
      unsigned long sizeOfLine = currentLine.size();
      if (sizeOfLine != 0) {
        shiza::helpers::trim(currentLine);
        cout << currentLine << endl;
      }
    }
  }
  fileStream.close();
}

shiza::ast::ASTNode* Lexer::lookingForNode(std::string line) const {
 std::string curr = line;
 int localPos = 0;
 shiza::helpers::trim(curr);
 while(localPos < line.length()) {

   localPos++;
 }
 return NULL;
};

__INHERIT_NODE__ tester() {
  return __INHERIT_NODE__{ "ParamNode", new shiza::ast::ParamNode("sasd", shiza::ast::INTEGER_TYPE, new shiza::ast::ASTNode()) };
};



class Parser {};

class Error {
  bool hasError;
  std::string stackTrace;
public:
  Error(const std::string stackTrace) {
    this->stackTrace = stackTrace;
    this->hasError = sizeof(stackTrace) != 0;
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
  shiza::FS fs;
  shiza::Lexer lexer;
  std::ifstream file = fs.read("C:\\Users\\Evgeniy\\Documents\\GitHub\\Shiza-programming-language\\src\\main.bmx");
  lexer.runLexicalAnalysis(file);
  shiza::__INHERIT_NODE__ root = shiza::tester();
  cout << root.name << endl;
  shiza::ast::ParamNode* node = static_cast<shiza::ast::ParamNode*>(root.value);
  cout << node->name << endl;
	return 0;
}


