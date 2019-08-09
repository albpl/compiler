/*
	The ALB Programming Language
	Alb Developers Team (C) 2019
	This software is distributed under the MIT license
	Visit https://github.com/albertonl/alb/LICENSE for further details
*/

#include "LabelFactory.hpp"
#include "Label.hpp"

alb_lang::Label alb_lang::LabelFactory::getNewLabel() {
  return Label{std::string{"label"} + std::to_string(lastLabel++)};
}