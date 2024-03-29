/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/
#ifndef ALB_RESOURCES_HPP
#define ALB_RESOURCES_HPP

#include "StringStore.hpp"

namespace alb_lang {
  class Resources {
  public:
    Resources() = delete;
    static StringStore& stringStore() {
      static StringStore ss {};
      return ss;
    }
  };
}

#endif //ALB_RESOURCES_HPP