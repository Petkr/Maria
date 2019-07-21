#include "Textures.hpp"

sf::Texture Textures::textures[Textures::count];

void Textures::Init()
{
	for (int i = 0; i != count; ++i)
	{
		textures[i].loadFromFile("resources/" + std::string(names[i]) + ".png");
	}
}

sf::Texture* Textures::Get(Textures::name n)
{
	return textures + n;
}