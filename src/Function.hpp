/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_FUNCTION_HPP
#define ALB_FUNCTION_HPP

#include "ExecutableOperation.hpp"
#include "ElementaryOperation.hpp"
#include <vector>

namespace alb_lang {
  class Function : ExecutableOperation {
  public:
    Function() = default;

    [[nodiscard]] std::vector<ElementaryOperation> flatten() const override;

    void addStep(const ExecutableOperation &step);

  private:
    std::vector<ExecutableOperation> steps{};
  };
}

#endif //ALB_FUNCTION_HPP