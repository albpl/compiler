/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_LABELFACTORY_HPP
#define ALB_LABELFACTORY_HPP

#include <cstdint>
#include <string>
#include "Label.hpp"

namespace alb_lang {
  class LabelFactory {
    friend class Resources;

  private:
    uint64_t lastLabel = 0;

    constexpr LabelFactory() = default;

  public:
    [[nodiscard]] Label getNewLabel();
  };
}

#endif //ALB_LABELFACTORY_HPP
