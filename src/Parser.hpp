/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_PARSER_HPP
#define ALB_PARSER_HPP

#include <vector>
#include "Token.hpp"
#include <queue>

namespace alb_lang {
  class Parser {
  private:
    Parser() = default;
    static void parseGlobalVars(std::queue<Token*>& tokenList);
    static void parseClosure(std::queue<Token*>& tokenList);
  public:
    static void parse(const std::vector<Token *> &tokenList);
  };
}

#endif //ALB_PARSER_HPP