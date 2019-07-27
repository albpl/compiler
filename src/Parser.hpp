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

namespace alb_lang {
  class Parser {
    friend class Resources;

  private:
    Parser() = default;

  public:
    void parse(std::vector<Token *> &tokenList);
  };
}

#endif //ALB_PARSER_HPP
