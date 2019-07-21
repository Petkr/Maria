#include "Button.hpp"

void Button::Check()
{
	if (contains(sf::Mouse::getPosition()))
		ClickHandler();
}