/*
	Test for ALB Program
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/

#include <gtest/gtest.h>
#include <include/alb-program.hpp>

TEST(alb_program_tests, alb_program_tests_test_constructor_Test) {
  ASSERT_NO_THROW(alb_lang::Program{});
}
