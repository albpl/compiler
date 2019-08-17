/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_LABEL_HPP
#define ALB_LABEL_HPP

#include "ElementaryOperation.hpp"
#include <vector>
#include <string>
#include <cstdint>

namespace alb_lang {
  class Label : public ElementaryOperation {
    friend class LabelFactory;

  public:
    [[nodiscard]] const std::string &getDebugString() const override;

    [[nodiscard]] const std::vector<uint8_t> &getBytes() const override;

    [[nodiscard]] const std::string &getAsmCode() const override;

    [[nodiscard]] const std::string &getName() const;

  private:
    explicit Label(const std::string &name);

    const std::string name;
    const std::vector<uint8_t> bytes{};
    const std::string asmCode;
  };
}

#endif //ALB_LABEL_HPP
