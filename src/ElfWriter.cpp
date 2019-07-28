/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include "ElfWriter.hpp"
#include <cstdio>

constexpr uint8_t FILE_HEADER[] = {
    0x7F, 'E', 'L', 'F',                // Magic number
    0x2,                                // 64-bit
    0x1,                                // Little endian
    0x1,                                // Version 1
    0x0,                                // Use no OS specific ABI - linux doesn't care either way, it seems
    0x0,                                // No ABI version
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  // Padding
};

constexpr uint8_t ELF_HEADER[] = {
    0x02, 0x00,               // Executable file
    0x3E, 0x00,               // AMD64
    0x01, 0x00, 0x00, 0x00,   // "Current" version
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Entry point is specified elsewhere
    0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x40 (section headers start) + 0x140 (5 section headers per 0x40 bytes) - program headers
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Section headers begin right after header
    0x00, 0x00, 0x00, 0x00,   // No processor specific flags
    0x40, 0x00,               // Whole elf file header is 64 bytes
    0x38, 0x00,               // Each program header entry is 56 bytes
    0x02, 0x00,               // We are having only 2 segments
    0x40, 0x00,               // Each section header is 64 bytes
    0x05, 0x00,               // There will be five sections: 0 .shstrtab .bss .data .text
    0x01, 0x00,               // Section name strings are stored in section 1 - .shstrtab
};

constexpr uint64_t DEFAULT_DATA_START_POINT = 0x400000;

void alb_lang::ElfWriter::write(const std::string& filename, WriterConfig config) {
  FILE* outFile = fopen(filename.c_str(), "w");
  fwrite(FILE_HEADER, 0x01, 0x10, outFile);
  fwrite(ELF_HEADER, 0x01, 0x30, outFile);
  auto writeSectionHeader = [outFile](uint8_t nameIndex, uint8_t sectionType, uint16_t flags, uint64_t address, uint64_t foffset, uint64_t size){
    uint8_t bytes[] = {
        nameIndex, 0x00, 0x00, 0x00,
        sectionType, 0x00, 0x00, 0x00,
        (uint8_t)(flags & 0x00FFu), (uint8_t)(((uint16_t)(flags & 0xFF00u)) >> 8u), 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Blame endiannes for those bitmasking hacks
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // address is set up just below
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // foffset is set up just below
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Size is set up just below
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Link + info are 0 - we don't need them
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // We don't want no alignment
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // We don't have no repeating entities
    };
    // Don't look at this. It assumes the compiler is compiled on little-endian platform. But it should work.
    ((uint64_t*) bytes)[2] = address;
    ((uint64_t*) bytes)[3] = foffset;
    ((uint64_t*) bytes)[4] = size;
    fwrite(bytes, 0x01, 0x40, outFile);
  };
  writeSectionHeader(0x00, 0, 0b00000000, 0, 0, 0); // Zero section
  writeSectionHeader(0x01, 3, 0b00000000, 0, 0x01F0, 0x1C); // .shstrtab
  writeSectionHeader(0x0B, 8, 0b00000011, DEFAULT_DATA_START_POINT, 0x020C, config.bss_size); // .bss
  writeSectionHeader(0x10, 1, 0b00000011, DEFAULT_DATA_START_POINT + config.bss_size, 0x020C, config.data.size()); // .data
  writeSectionHeader(0x16, 1, 0b00000110, DEFAULT_DATA_START_POINT - config.text.size(), 0x020C + config.data.size(), config.text.size()); // .text

  uint8_t segment1[] = {
      0x01, 0x00, 0x00, 0x00, // Segment loaded into memory
      0x06, 0x00, 0x00, 0x00, // Read-write
      0x0C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // The program headers resist at 0x0180, + 0x70 of the headers themselves + 0x1C of strings
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - memory address
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // We are just ignoring physical addressing
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - size in file
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - size in memory
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // No alignment necessary
  };
  ((uint64_t*)segment1)[2] = DEFAULT_DATA_START_POINT;
  ((uint64_t*)segment1)[4] = config.data.size(); // +1 for bss
  ((uint64_t*)segment1)[5] = config.data.size() + config.bss_size;


  uint8_t segment2[] = {
      0x01, 0x00, 0x00, 0x00, // Segment loaded into memory
      0x05, 0x00, 0x00, 0x00, // Read-execute
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - file offset
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - memory address
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // We are just ignoring physical addressing
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - size in file
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Set up just below - size in memory
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // No alignment necessary
  };
  ((uint64_t*)segment2)[1] = 0x020C + config.data.size();
  ((uint64_t*)segment2)[2] = DEFAULT_DATA_START_POINT - config.text.size();
  ((uint64_t*)segment2)[4] = config.text.size();
  ((uint64_t*)segment2)[5] = config.text.size();

  fwrite(segment1, 0x01, sizeof(segment1), outFile);
  fwrite(segment2, 0x01, sizeof(segment2), outFile);

  constexpr char strings[] = {
    // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
      0x0, '.', 's', 'h', 's', 't', 'r', 't', 'a', 'b', 0x0, '.', 'b', 's', 's', 0x0, // 0x0X
      '.', 'd', 'a', 't', 'a', 0x0, '.', 't', 'e', 'x', 't', 0x0,                     // 0x1X
  };

  fwrite(strings, 0x01, sizeof(strings), outFile);
  fwrite(config.data.data(), 0x01, config.data.size(), outFile);
  fwrite(config.text.data(), 0x01, config.text.size(), outFile);
  fseek(outFile, 24, SEEK_SET);
  const auto textStart = (uint64_t) (DEFAULT_DATA_START_POINT - config.text.size());
  fwrite(&textStart, 0x01, 0x08, outFile);
  fclose(outFile);
}
