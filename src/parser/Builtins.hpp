/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_BUILTINS_HPP
#define ALB_BUILTINS_HPP

#include "../Function.hpp"
#include "../platform/x64/ops/Mov.hpp"
#include "Variable.hpp"

namespace alb_lang {
  class Builtins {
  public:
    static Function out(Variable var) {
      Function f {};
      f.addStep(Mov{rax, 1});
      f.addStep(Mov{rdi, 1});
      f.addStep(Mov{})
    }
  };
}

#endif //ALB_BUILTINS_HPP
