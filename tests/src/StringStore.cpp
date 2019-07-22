/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include <gtest/gtest.h>
#include <StringStore.hpp>
#include <Resources.hpp>

TEST(StringStore, counter_incrementation) {
  alb_lang::StringStore stringStore = alb_lang::Resources::stringStore();
  int stringLiteralCount = stringStore.getStringLiteralCount();
  stringStore.storeString("test");
  ASSERT_EQ(stringStore.getStringLiteralCount(), stringLiteralCount + 1);
}

TEST(StringStore, string_retrieval) {
  alb_lang::StringStore stringStore = alb_lang::Resources::stringStore();
  std::string id = stringStore.storeString("test1");
  stringStore.storeString("test2");
  const std::string &returnedString = stringStore.getString(id);
  ASSERT_EQ(returnedString.compare("test1"), 0);
}
