#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Geometry.hpp"
#include "Level.hpp"

class GameObject
{
	Level& level;
	sf::RectangleShape rectangle_shape;
public:
	GameObject(Level& level, const sf::FloatRect& rectangle);
};