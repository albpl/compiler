/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_MOV_HPP
#define ALB_MOV_HPP

#include <cstdint>
#include "../../../ElementaryOperation.hpp"
#include "../Registers.hpp"
#include <string>
#include <vector>

namespace alb_lang {
  class Mov : ElementaryOperation {
  public:
    Mov(Register target_register, int64_t literal);

    [[nodiscard]] const std::string &getDebugString() const override;

    [[noreturn]] const std::vector<uint8_t> &getBytes() const override;

    [[nodiscard]] const std::string &getAsmCode() const override;

  private:
    const std::vector<uint8_t> bytes;
    const std::string asmCode;
  };
}


#endif //ALB_MOV_HPP
