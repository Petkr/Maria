#include "Resources.hpp"
#include <fstream>

Resources::Resources()
	: textures("textures")
	, images("images")
	, texts("texts")
	, levels("levels")
	, fonts("fonts")
{}

void Text::loadFromFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	file >> *this;
}