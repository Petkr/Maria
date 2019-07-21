#pragma once
#include "MovableObject.hpp"
#include <vector>
#include <string>

class Level
{

public:
	std::vector<GameObject*> objects;
	std::vector<MovableObject*> movables;

	Level(const std::string& name);

	void Remove(const GameObject& object);
};