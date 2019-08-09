/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_ELEMENTARYOPERATION_HPP
#define ALB_ELEMENTARYOPERATION_HPP

#include <string>
#include <vector>
#include <cstdint>
#include "ExecutableOperation.hpp"

namespace alb_lang {
  class ElementaryOperation : ExecutableOperation {
  public:
    [[nodiscard]] std::vector<ElementaryOperation> flatten() const override {
      std::vector<ElementaryOperation> ret{};
      ret.push_back(*this);
      return ret;
    }

    [[nodiscard]] virtual const std::string &getDebugString() const = 0;

    [[nodiscard]] virtual const std::vector<uint8_t> &getBytes() const = 0;

    [[nodiscard]] virtual const std::string &getAsmCode() const = 0;
  };
}

#endif //ALB_ELEMENTARYOPERATION_HPP
