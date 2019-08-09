/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include "Mov.hpp"
#include <string>
#include <cstdint>
#include <vector>
#include "../../../PrettyAsm.hpp"
#include <stdexcept>

const std::string &alb_lang::Mov::getDebugString() const {
  return asmCode;
}

const std::vector<uint8_t> &alb_lang::Mov::getBytes() const {
  throw std::logic_error{"Not implemented"};
}

const std::string &alb_lang::Mov::getAsmCode() const {
  return asmCode;
}

alb_lang::Mov::Mov(alb_lang::Register target_register, int64_t literal) : asmCode(
    prettifyAsm("MOV", target_register, literal)), bytes({0}) {}
