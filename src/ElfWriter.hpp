/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#ifndef ALB_ELFWRITER_HPP
#define ALB_ELFWRITER_HPP

#include <string>
#include <cstdint>
#include <vector>

namespace alb_lang {

  struct WriterConfig {
    const std::vector<uint8_t>& data;
    const std::vector<uint8_t> text;
    uint64_t bss_size;
  };

  class ElfWriter {
  public:
    void write(const std::string& filename, WriterConfig config);
  };
}

#endif //ALB_ELFWRITER_HPP
