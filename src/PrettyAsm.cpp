/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#include "PrettyAsm.hpp"
#include <absl/strings/str_format.h>

namespace alb_lang {
  std::string prettifyAsm(const std::string &instructionName, Register r, uint64_t literal) {
    return absl::StrFormat("%-16s%-16s%-8s%.16X", instructionName, toString(r), ",", literal);
  };

  std::string prettifyAsm(const std::string &instructionName) {
    return absl::StrFormat("%-16s", instructionName);
  };
}