#include "GameObject.hpp"

GameObject::GameObject(Level& level, const Rectangle& rect)
	: rectangle({ rect.width, rect.height })
	, level(level)
{
	rectangle.setPosition(rect.left, rect.top);
}

void GameObject::Die()
{
	
}