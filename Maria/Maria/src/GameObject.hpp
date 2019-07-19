#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

class GameObject
{

public:
	sf::Vector2i position;

	GameObject(sf::Vector2i position);

	virtual void Die();

	virtual sf::Texture GetTexture() = 0;

	virtual ~GameObject() = default;
};