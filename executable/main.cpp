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

  const char *str = "Hello";
  std::vector<uint8_t> data {str, str + 6};

  const uint8_t text[] = { 0xb8, 0x01, 0x00, 0x00, 0x00,
                           0xbf, 0x01, 0x00, 0x00, 0x00,
                           0x48, 0xBE, 0x01, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
                           0xBA, 0x05, 0x00, 0x00, 0x00,
                           0x0F, 0x05,
                           0xb8, 0x3c, 0x00, 0x00, 0x00,
                           0xbf, 0x00, 0x00, 0x00, 0x00,
                           0x0F, 0x05 };
  alb_lang::ElfWriter{}.write("Whatever", {data, std::vector(text, text + sizeof(text)), 0});

	return 0;
}
