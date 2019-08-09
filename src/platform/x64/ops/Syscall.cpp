/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include "Syscall.hpp"
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdint>
#include "../../../PrettyAsm.hpp"

const std::string &alb_lang::Syscall::getDebugString() const {
  return getAsmCode();
}

const std::vector<uint8_t> &alb_lang::Syscall::getBytes() const {
  throw std::logic_error{"Not implemented"};
}

const std::string &alb_lang::Syscall::getAsmCode() const {
  return asmCode;
}

alb_lang::Syscall::Syscall() : asmCode(prettifyAsm("SYSCALL")) {}
