#include "GameObject.hpp"

GameObject::GameObject(Level& level, const sf::FloatRect& rectangle)
	: level(level)
	, rectangle_shape(size(rectangle))
{
	rectangle_shape.setPosition(position(rectangle));
}