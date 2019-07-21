#pragma once
#include "Geometry.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Button
{
	sf::RectangleShape rectangle;

public:


	void (*ClickHandler)();
	
	void Check();
};