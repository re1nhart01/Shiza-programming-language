#pragma once

#ifndef AST_H
#define AST_H

#include <string>
#include <vector>

namespace shiza::ast::Tokens {
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
    }


#endif