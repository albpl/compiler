/*
	Test for Lexer
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/

#include <gtest/gtest.h>
#include <include/Lexer.hpp>

TEST(tokenizer_tests, tokenizer_tests_constructor_Test) {
  ASSERT_NO_THROW(alb_lang::Lexer{});
}

TEST(tokenizer_tests, tokenizer_tests_utf8_parsing_token_count_Test) {
  char testData[] = "BEGIN .\nEND";
  std::vector<alb_lang::Token*> tokens;
  alb_lang::Lexer::tokenizeUTF8(testData, sizeof(testData), tokens);
  ASSERT_EQ(tokens.size(), 3);
}

TEST(tokenizer_tests, tokenizer_tests_utf8_parsing_comment_Test) {
  char testData[] = "BEGIN .\n// This is a comment\nEND";
  std::vector<alb_lang::Token*> tokens;
  alb_lang::Lexer::tokenizeUTF8(testData, sizeof(testData), tokens);
  EXPECT_EQ(tokens.size(), 3);
  EXPECT_EQ(tokens[0]->getTextContents(), std::string{"BEGIN"});
  EXPECT_EQ(tokens[1]->getTextContents(), std::string{"."});
  EXPECT_EQ(tokens[2]->getTextContents(), std::string{"END"});
}

TEST(tokenizer_tests, tokenizer_tests_utf8_parsing_multiline_comment_Test) {
  char testData[] = "BEGIN .\n/*This is\na comment*/END";
  std::vector<alb_lang::Token*> tokens;
  alb_lang::Lexer::tokenizeUTF8(testData, sizeof(testData), tokens);
  EXPECT_EQ(tokens.size(), 3);
  EXPECT_EQ(tokens[0]->getTextContents(), std::string{"BEGIN"});
  EXPECT_EQ(tokens[1]->getTextContents(), std::string{"."});
  EXPECT_EQ(tokens[2]->getTextContents(), std::string{"END"});
}
