/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_PRETTYASM_HPP
#define ALB_PRETTYASM_HPP

#include <string>
#include "platform/x64/Registers.hpp"
#include <cstdint>

namespace alb_lang {
  [[nodiscard]] std::string prettifyAsm(const std::string &instructionName, Register r, uint64_t literal);

  [[nodiscard]] std::string prettifyAsm(const std::string &instructionName);
}

#endif //ALB_PRETTYASM_HPP
