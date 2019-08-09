/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_EXECUTABLEOPERATION_HPP
#define ALB_EXECUTABLEOPERATION_HPP

#include <vector>

namespace alb_lang {
  class ExecutableOperation {
  public:
    [[nodiscard]] virtual std::vector<class ElementaryOperation> flatten() const = 0;
  };
}

#endif //ALB_EXECUTABLEOPERATION_HPP
