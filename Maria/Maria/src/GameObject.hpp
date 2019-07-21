#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Geometry.hpp"
#include "Level.hpp"

class GameObject
{
	sf::RectangleShape rectangle;
	Level& level;
public:
	GameObject(Level& level, const Rectangle& rect);

	void Die();
	
	virtual sf::Texture* GetTexture() = 0;

	virtual ~GameObject() = default;
};