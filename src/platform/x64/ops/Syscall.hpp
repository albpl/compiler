/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_SYSCALL_HPP
#define ALB_SYSCALL_HPP

#include "../../../ElementaryOperation.hpp"
#include <string>
#include <vector>
#include <cstdint>

namespace alb_lang {
  class Syscall : ElementaryOperation {
  public:
    Syscall();

    [[nodiscard]] const std::string &getDebugString() const override;

    [[noreturn]] const std::vector<uint8_t> &getBytes() const override;

    [[nodiscard]] const std::string &getAsmCode() const override;

  private:
    const std::string asmCode;
  };
}

#endif //ALB_SYSCALL_HPP
