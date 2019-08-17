/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_PROGRAMSPACE_HPP
#define ALB_PROGRAMSPACE_HPP

#include <utility>
#include <vector>
#include "ElementaryOperation.hpp"
#include "Label.hpp"
#include <cstdint>

namespace alb_lang {
  struct BssSpaceRequest {
    const Label& label;
    uint64_t bytes;
    BssSpaceRequest(const Label& label, uint64_t bytes) : label(label), bytes(bytes) { }
  };
  class ProgramSpace {
    friend class Resources;
  private:
    std::vector<ElementaryOperation> textSpace;
    std::vector<ElementaryOperation> dataSpace;
    std::vector<BssSpaceRequest> bssSpace;
    ProgramSpace() = default;

  public:
    void addText(const std::vector<ElementaryOperation>& text) {
      textSpace.insert(textSpace.end(), text.begin(), text.end());
    }
    void addData(const std::vector<ElementaryOperation>& data) {
      dataSpace.insert(dataSpace.end(), data.begin(), data.end());
    }
    void addBss(const BssSpaceRequest& request) {
      bssSpace.push_back(request);
    }
  };
}

#endif //ALB_PROGRAMSPACE_HPP
