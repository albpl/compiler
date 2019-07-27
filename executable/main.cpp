/*
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/

#include <cstdio>
#include <string>
#include <ElfWriter.hpp>
#include <vector>
#include <cstdint>

int main(int argc, char const *argv[]){
	if (argc < 2) {
	  printf("Please provide name of the file to execute as first argument. All other parameters are ignored.");
	} else {
    const std::string fileName = argv[1];
  }

  const char *string = "Hello";
  std::vector<uint8_t> data {string, string + 5};
  data.push_back(5);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  const uint8_t text[] = { 0x48, 0xC7, 0xC0, 0x01, 0x00, 0x00, 0x00, 0x48, 0xC7, 0xC7, 0x01, 0x00, 0x00, 0x00, 0x48, 0xC7, 0xC6, 0x00, 0x00, 0x40, 0x00, 0x48, 0xC7, 0xC2, 0x05, 0x00, 0x40, 0x00, 0x0F, 0x05, 0x48, 0xC7, 0xC0, 0x3C, 0x00, 0x00, 0x00, 0x48, 0xC7, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x05 };
  alb_lang::ElfWriter{}.write("Whatever", {data, std::vector(text, text + sizeof(text)), 0});

	return 0;
}
