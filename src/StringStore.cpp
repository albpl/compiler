/*
	The ALB Programming Language
	ALB Developers Team (C) 2019

	This software is distributed under the MIT license
	Visit https://github.com/albpl/compiler/blob/master/LICENSE for further details
*/


#include <vector>
#include <string>
#include <absl/strings/str_split.h>
#include <absl/strings/numbers.h>
#include "CompilerDirectiveChecks.hpp"
#include "StringStore.hpp"

namespace alb_lang {

  int StringStore::getStringLiteralCount() const {
    return strings.size();
  }

  std::string StringStore::storeString(const std::string &s) {
    strings.push_back(s);
    return "::internal::strings::" + std::to_string(strings.size() - 1);
  }

  std::string StringStore::getString(const std::string &id) const {
    std::vector<std::string> strParts = absl::StrSplit(id, "::");
    assertDirectiveIsInternal(strParts);
    long numStringId = 0;
    if (strParts.size() < 4 || strParts[2] != "strings" || !absl::SimpleAtoi(strParts[3], &numStringId)) {
      throw (std::runtime_error{
          "Given string is not a valid string identifier"
      });
    }
    return strings[numStringId];
  }
}

