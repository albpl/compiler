/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include "Label.hpp"
#include "PrettyAsm.hpp"
#include <vector>
#include <string>
#include <cstdint>

const std::string &alb_lang::Label::getDebugString() const {
  return asmCode;
}

const std::vector<uint8_t> &alb_lang::Label::getBytes() const {
  return bytes;
}

const std::string &alb_lang::Label::getAsmCode() const {
  return asmCode;
}

alb_lang::Label::Label(const std::string &name) : asmCode(prettifyAsm(name + ":")), name(name) {}

const std::string &alb_lang::Label::getName() const {
  return name;
}
