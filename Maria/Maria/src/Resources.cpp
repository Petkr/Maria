#include "Resources.hpp"
#include <fstream>
#include <iostream>

Resources::Resources()
	: textures("textures")
	, images("images")
	, texts("texts")
	, levels("levels")
	, fonts("fonts")
{}

template <>
void loadFromFile<std::string>(std::string& res, const std::string& filename)
{
	std::ifstream file(filename);
	res = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}