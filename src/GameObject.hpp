#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Geometry.hpp"

class Level;

class GameObject
{
	Level& level;
	sf::RectangleShape rectangle_shape;
public:
	GameObject(Level& level, const sf::FloatRect& rectangle);

	Vector Size() const;
	Vector Position() const;

	virtual bool Solid() const = 0;
	virtual bool OnCollisionWith(GameObject& object) = 0;
};