/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#include "Function.hpp"
#include "ElementaryOperation.hpp"
#include <vector>

std::vector<alb_lang::ElementaryOperation> alb_lang::Function::flatten() const {
  std::vector<ElementaryOperation> ret{};
  for (const auto &step : steps) {
    const std::vector<struct ElementaryOperation> &flattened = step.flatten();
    ret.insert(ret.end(), flattened.begin(), flattened.end());
  }
  return ret;
}

void alb_lang::Function::addStep(const ExecutableOperation &step) {
  steps.push_back(step);
}

int alb_lang::Function::getParamAmount() const {
  return paramAmount;
}
