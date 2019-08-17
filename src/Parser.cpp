/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#include "Parser.hpp"
#include <queue>
#include <stdexcept>
#include <vector>
#include <string>
#include "Function.hpp"

void alb_lang::Parser::parse(const std::vector<Token *> &_tokenList) {
  std::queue<Token *> tokenList{};
   for (const auto token : _tokenList) {
    tokenList.push(token);
  }

  while (!tokenList.empty()) {
    const std::string &token = tokenList.front()->getTextContents();
    tokenList.pop();
    if (token == "var") {
      parseGlobalVars(tokenList);
    } else if (token == "BEGIN") {
      const std::string &closureName = tokenList.front()->getTextContents();
      tokenList.pop();
      parseClosure(tokenList);
    }
  }
}

void alb_lang::Parser::parseGlobalVars(std::queue<Token *> &tokenList) {
  throw std::logic_error {"Unimplemented!"};
}

alb_lang::Function alb_lang::Parser::parseClosure(std::queue<Token *> &tokenList) {
  Function ret {};

}
