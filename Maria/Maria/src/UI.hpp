#pragma once
#include "Button.hpp"
#include <vector>

class UI
{
public:
	std::vector<Button> buttons;

	static constexpr int margin = 10;
};