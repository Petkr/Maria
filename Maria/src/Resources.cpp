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
void loadFromFile<std::string>(std::string& s, const std::string& filename)
{
	std::ifstream file(filename);
	file.seekg(0, std::ios::end);
	std::vector<char> buffer;
	file.seekg(0);
	file.read(str, s.capacity());

	std::cout << s.capacity() << std::endl;
}