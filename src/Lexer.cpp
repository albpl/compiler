/*
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/

#include <cstdint>
#include <vector>
#include "Token.hpp"
#include <stdexcept>
#include "Lexer.hpp"

namespace alb_lang {

  constexpr bool Lexer::isCharacterWhitespace(uint32_t codepoint) noexcept {
    switch (codepoint) {
      case 0x0000:
      case 0x0009:
      case 0x000A:
      case 0x000B:
      case 0x000C:
      case 0x000D:
      case 0x0020:
      case 0x0085:
      case 0x00A0:
      case 0x1680:
      case 0x2000:
      case 0x2001:
      case 0x2002:
      case 0x2003:
      case 0x2006:
      case 0x2004:
      case 0x2005:
      case 0x2007:
      case 0x2008:
      case 0x2009:
      case 0x200A:
      case 0x2028:
      case 0x2029:
      case 0x202F:
      case 0x205F:
      case 0x3000:
      case 0x200B:
      case 0x2060:
      case 0xFEFF:
      case 0x00B7:
      case 0x237D:
      case 0x2420:
      case 0x2422:
      case 0x2423:
        return true;
      default:
        return false;
    }
  }

  constexpr bool Lexer::isCharacterNewline(uint32_t codepoint) noexcept {
    switch (codepoint) {
      case 0x000A:
      case 0x000B:
      case 0x000C:
      case 0x000D:
      case 0x0085:
      case 0x2028:
      case 0x2029:
        return true;
      default:
        return false;
    }
  }

  constexpr bool Lexer::isCharacterSpecialMeaning(uint32_t codepoint) noexcept {
    if (codepoint > 127) { // Character is not in ASCII range -> it is not a special meaning char
      return false;
    }
    switch ((uint8_t) codepoint) {
      case '+':
      case '*':
      case '-':
      case '/':
      case '=':
      case '(':
      case ')':
      case '{':
      case '}':
      case '[':
      case ']':
      case '%':
      case '?':
      case ':':
      case ';':
      case '.':
      case ',':
      case '^':
      case '&':
      case '|':
      case '<':
      case '>':
      case '~':
      case '!':
      case '"':
      case '\'':
        return true;
      default:
        return false;
    }
  }

  uint32_t Lexer::getNextChar(unsigned char *utf8Data, uint64_t &currindex) noexcept(false) {
    if (((utf8Data[currindex]) & 0b10000000u) == 0) {
      return utf8Data[currindex++];
    }
    if ((utf8Data[currindex] & 0b11100000u) == 0b11000000) {
      const uint32_t firstByteBits = utf8Data[currindex++] & 0b00011111u;
      const uint32_t secondByteBits = utf8Data[currindex++] & 0b00111111u;
      return (firstByteBits << 6u) + secondByteBits;
    }
    if ((utf8Data[currindex] & 0b11110000u) == 0b11100000) {
      const uint32_t firstByteBits = utf8Data[currindex++] & 0b00001111u;
      const uint32_t secondByteBits = utf8Data[currindex++] & 0b00111111u;
      const uint32_t thirdByteBits = utf8Data[currindex++] & 0b00111111u;
      return (firstByteBits << 12u) + (secondByteBits << 6u) + thirdByteBits;
    }
    if ((utf8Data[currindex] &0b11111000u) == 0b11110000u) {
      const uint32_t firstByteBits = utf8Data[currindex++] & 0b00000111u;
      const uint32_t secondByteBits = utf8Data[currindex++] & 0b00111111u;
      const uint32_t thirdByteBits = utf8Data[currindex++] & 0b00111111u;
      const uint32_t fourthByteBits = utf8Data[currindex++] & 0b00111111u;
      return (firstByteBits << 18u) + (secondByteBits << 12u) + (thirdByteBits << 6u) + fourthByteBits;
    }
    throw std::runtime_error{"Invalid UTF-8 data."};
  }

  void Lexer::tokenizeUTF8(char *utf8Data, uint64_t dataSize, std::vector<Token*> &tokenList) {
    uint64_t startindex=0, endindex= 0, currindex = 0;
    while (currindex < dataSize) {
      endindex = currindex - 1;
      uint32_t nextChar = getNextChar((unsigned char*)(utf8Data), currindex);
      if (isCharacterWhitespace(nextChar) || isCharacterSpecialMeaning((nextChar))) {
        if (!(endindex < startindex || endindex == UINT64_MAX)) {
          tokenList.push_back(new BasicToken{std::string{(char *) utf8Data + startindex, endindex - startindex + 1}});
        }
        startindex = currindex;
        if (isCharacterSpecialMeaning(nextChar)) {


          // Handle comments in code
          if (nextChar == '/') {
            if (currindex < dataSize) {
              uint64_t tempCurrindex = currindex;
              uint32_t nextNextChar = getNextChar((unsigned char*)(utf8Data), tempCurrindex);
              if (nextNextChar == '/' || nextNextChar == '*') {
                getNextChar((unsigned char*)utf8Data, currindex); // To get currindex past nextNextChar
                while (currindex < dataSize) {
                  uint32_t nextInCommentChar = getNextChar((unsigned char*)utf8Data, currindex);
                  if (nextNextChar == '/' && isCharacterNewline(nextInCommentChar)) {
                    break;
                  } else if (nextNextChar == '*' && nextInCommentChar == '*') {
                    uint64_t anotherTempCurrIndex = currindex;
                    uint32_t nextNextInCommentChar = getNextChar((unsigned char*) utf8Data, anotherTempCurrIndex);
                    if (nextNextInCommentChar == '/') {
                      getNextChar((unsigned char*) utf8Data, currindex); // To get currindex past nextNextInCommentChar
                      break;
                    }
                  }
                }
                startindex = currindex;
                continue;
              }
            }
          }


          tokenList.push_back(new BasicToken{std::string{(char)nextChar}});
        }
      }
    }
  }
}

