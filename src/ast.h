#pragma once

#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

// NO EVAL SKA BLYAT

namespace shiza::ast {

enum DATA_TYPES {
  INTEGER_TYPE,
  STRING_TYPE,
  BOOL_TYPE,
};

enum TokenType {
  // Keywords
  INT,
  FLOAT,
  STRING,
  STRING_TEMPLATE, // `#()`
  // Identifiers and literals
  IDENTIFIER,
  LITERAL,
  // Operators
  // Binary
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  // Unary
  UNARY_PLUS, // ++aboba
  UNARY_MINUS, // --aboba
  UNARY_MULTIPLY, // **aboba
  UNARY_DIVIDE, // //aboba
  // Delimiters
  SEMICOLON,
  COMMA,
  // Parentheses
  LEFT_PAREN,  // [
  RIGHT_PAREN, // ]
  LEFT_BRACKET, // ( - scope bracket
  RIGHT_BRACKET, // ) - scope bracket
  // Other token types
  ASSIGNMENT,
  EOF_TOKEN, // End of file token
  // Comments
  SINGLE_COMMENT, // @@ aboba
  MULTIPLE_COMMENT, // /@ aboba @/

  // FUNCTIONAL_KEYWORDS
  LOG, // log
  WARNING, // warning
  ERROR, // error

  // MISC
  JS_PASTE, // ..js ()
  CPP_PASTE, // cpp (  )
};

class ASTNode {
public:
  size_t start_line = 0;
  size_t start_column = 0;
  size_t end_line = 0;
  size_t end_column = 0;

  virtual ~ASTNode() = default;
};

class PackageNode final : public ASTNode {
public:
  std::string name;
  PackageNode(const std::string name) {
    this->name = name;
  }
};

class CallNode final : public ASTNode {};

class ParamNode final : public ASTNode {
public:
  std::string name;
  DATA_TYPES type;
  ASTNode* value;
  ParamNode(std::string name, DATA_TYPES type, ASTNode* value) {
   this->name = name;
   this->type = type;
   this->value = value;
 } 
}; 

class FunctionNode final : public ASTNode {
public:
  bool isAsync;
  std::string name;
  std::vector<ParamNode*> params;
  std::vector<ParamNode*> return_types;
  std::vector<ASTNode*> body;
  FunctionNode(
      const std::string name,
      const std::vector<ParamNode*> params,
      const std::vector<ParamNode*> return_types,
      std::vector<ASTNode*> body
      ) {
    this->name = name;
    this->params = params;
    this->return_types = return_types;
    this->body = body;
  }
};

class DefineNode final : public ASTNode {
  public:
  std::string name;
  ASTNode* value;
  DATA_TYPES type;
  DefineNode(const std::string name, ASTNode* value, const DATA_TYPES type) {
    this->name = name;
    this->value = value;
    this->type = type;
  }
};

class LogNode final : public ASTNode {
  private:
  enum LOG_TYPE {
    ERROR,
    LOG,
    WARN,
  };
  
  public:
    LOG_TYPE type;
    ASTNode* value;
    LogNode(const LOG_TYPE type, ASTNode* value) {
      this->type = type;
      this->value = value;
    }
};

/*
*class TypeValueNode final : public ASTNode {
public:
  ASTNode* left;
  ASTNode* right;
  std::string op;
};
*
* */

}


#endif