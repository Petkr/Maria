#include "GameObject.hpp"

GameObject::GameObject(Level& level, const Rectangle& rectangle)
	: level(level)
	, rectangle_shape(size(rectangle))
{
	rectangle_shape.setPosition(position(rectangle));
}