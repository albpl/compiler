/*
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/
#ifndef ALB_BASICTOKEN_HPP
#define ALB_BASICTOKEN_HPP

#include "../Token.hpp"

namespace alb_lang {
  /**
   * Generic unspecified token.
   */
  class BasicToken : public alb_lang::Token {
    const std::string textContents;
  public:
    /**
     * Creates new instance with specified \c textContents
     * @param textContents Text this Token encapsulates
     */
    explicit BasicToken(std::string textContents) : textContents(std::move(textContents)) {}

    [[nodiscard]] const std::string &getTextContents() const override {
      return textContents;
    }
  };
}

#endif //ALB_BASICTOKEN_HPP
