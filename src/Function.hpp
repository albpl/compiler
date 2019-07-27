/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_FUNCTION_HPP
#define ALB_FUNCTION_HPP

#include <string>
#include <utility>
#include <vector>
#include <cstdint>

namespace alb_lang {
  class Function {
    friend class FunctionStore;

  private:
    bool isElem;
    std::string name;
    std::vector<uint8_t> bytes;
    std::vector<Function> subFunctions;

    Function(std::string name, std::vector<uint8_t> bytes) : isElem(true), name(std::move(name)),
                                                             bytes(std::move(bytes)), subFunctions() {};
    Function(std::string name, std::vector<Function> subFunctions) : isElem(true), name(std::move(name)),
                                                             bytes(), subFunctions(std::move(subFunctions)) {};

  public:
    bool isElemental() { return isElem; };

    std::string getName() { return name; };

    std::vector<uint8_t> getBytes() { return bytes; };

    std::vector<Function> getSubFunctions() { return subFunctions; };
  };
}

#endif //ALB_FUNCTION_HPP
