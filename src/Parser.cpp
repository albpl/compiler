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

namespace alb_lang {
  void Parser::parse(std::vector<Token *> &_tokenList) {
    std::vector<std::vector<Token *>> globalVars;
    std::queue<Token *> tokenList {};
    auto errorIfNoMoreTokens = [&tokenList] {
      if (tokenList.empty()) {
        throw std::runtime_error{"Unexpected EOF."};
      }
    };
    for (const auto token : _tokenList) {
      tokenList.push(token);
    }
    while (!tokenList.empty()) {
      std::string currentToken = tokenList.front()->getTextContents();
      tokenList.pop();
      if (currentToken == "var") {
        errorIfNoMoreTokens();
        if (tokenList.front()->getTextContents() != "{") {
          throw std::runtime_error{"Unexpected " + tokenList.front()->getTextContents()};
        }
        tokenList.pop();
        int openCurlyBraces = 1;
        std::vector<Token *> currentVar {};
        while (openCurlyBraces > 0) {
          errorIfNoMoreTokens();
          currentToken = tokenList.front()->getTextContents();
          tokenList.pop();
          if (currentToken == "}") {
            openCurlyBraces--;
            if (openCurlyBraces == 0 && !currentVar.empty()) {
              globalVars.push_back(currentVar);
            }
          } else if (currentToken == "{") {
            openCurlyBraces++;
          } else if (currentToken == ";" && openCurlyBraces == 1) {
            globalVars.push_back(currentVar);
            currentVar = std::vector<Token *> {};
          }
        }
      } else if (currentToken == "BEGIN") {
        errorIfNoMoreTokens();

      }
    }
  }
}
