/*
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/
#ifndef ALB_LEXER_HPP
#define ALB_LEXER_HPP

#include <cstdint>
#include <vector>
#include "Token.hpp"

namespace alb_lang {
  /**
   * Performs lexical analysis of input data (parsing the text).
   */
  class Lexer {
  private:
    /**
     * Returns true if codepoint passed represents a valid whitespace character.
     *
     * Valid whitespace character codepoints are:
     * - U+0000 (NULL)
     * - U+0009 (tab)
     * - U+000A (LF)
     * - U+000B (VT)
     * - U+000C (FF)
     * - U+000D (CR)
     * - U+0020 (space)
     * - U+0085 (unicode NEXT LINE)
     * - U+00A0 (nbsp)
     * - U+1680 (Ogham space)
     * - U+2000 (en space, variant 1)
     * - U+2001 (em space, variant 1)
     * - U+2002 (en space, variant 2)
     * - U+2003 (em space, variant 2)
     * - U+2004 (one third of em space)
     * - U+2005 (one fourth of em space)
     * - U+2006 (one sixth of em space)
     * - U+2007 (figure space)
     * - U+2008 (punctuation space)
     * - U+2009 (thin space)
     * - U+200A (hair space)
     * - U+2028 (line separator)
     * - U+2029 (paragraph separator)
     * - U+202F (narrow nbsp)
     * - U+205F (medium mathspace)
     * - U+3000 (some other space)
     * - U+200B (zero width space)
     * - U+2060 (word joiner (zero width nbsp))
     * - U+FEFF (deprecated zero width nbsp)
     *
     * Also, this method returns true for some technically non-whitespace
     * characters, which are however included if only just for fun:
     * - U+00B7 (interpunct - · )
     * - U+237D (visual representation of nbsp - ⍽ )
     * - U+2420 (symbol for space - ␠ )
     * - U+2422 (symbol for blank - ␢ )
     * - U+2423 (handwriting symbol for space - ␣ )
     *
     * @param codepoint The unicode codepoint for which to check for whitespaceness.
     * @return true when the character is whitespace from the upper list
     */
    static constexpr bool isCharacterWhitespace(uint32_t codepoint) noexcept;

    /**
     * Returns true if codepoint passed represents a valid newline character.
     *
     * Valid newline character codepoints are:
     * - U+000A (LF)
     * - U+000B (VT)
     * - U+000C (FF)
     * - U+000D (CR)
     * - U+0085 (unicode NEXT LINE)
     * - U+2028 (line separator)
     * - U+2029 (paragraph separator)
     *
     * @param codepoint The unicode codepoint which to check
     * @return true when the character is newline from the upper list
     */
    static constexpr bool isCharacterNewline(uint32_t codepoint) noexcept;

    /**
     * Returns true if codepoint passed represents a character with special meaning in alb.
     *
     * These characters are all in the ASCII range, and specifically are:
     * - \c +*-/ for basic math operations
     * - \c = for assignments, also in \c == and variants for comparing
     * - \c (){}[] as ever useful brackets
     * - \c % for modulo operation
     * - \c ?: as "conditional operator" (also known as ternary operator)
     * - \c ;., for generic separating/chaining
     * - \c ^&|<>~ as bitwise operators
     * - \c ! for logical negation
     * - \c "' for marking strings
     *
     * @param codepoint The unicode codepoint for which to check for special meaning.
     * @return true when the character has special meaning assigned
     */
    static constexpr bool isCharacterSpecialMeaning(uint32_t codepoint) noexcept;

    /**
     * Returns next character as unicode codepoint from the block of input data.
     * @param utf8Data Block of UTF-8 input data.
     * @param currindex The index of the first byte of the next character
     * @return The next character as unicode codepoint
     */
    static uint32_t getNextChar(unsigned char *utf8Data, uint64_t &currindex) noexcept(false);

  public:
    Lexer() = default;

    /**
     * Performs lexical analysis of input data in \c utf8Data, appending them to \c tokenList
     * @param utf8Data Pointer to the beginning of the block of data
     * @param dataSize Complete size of the data
     * @param tokenList Reference to vector to append the tokens to.
     */
    static void tokenizeUTF8(char *utf8Data, uint64_t dataSize, std::vector<Token *> &tokenList) noexcept(false);
  };
}

#endif //ALB_LEXER_HPP
