#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <map>
#include <vector>
#include <filesystem>

class Text : public std::string
{
public:
	void loadFromFile(const std::string& filename);
};

class Resources
{
	template <typename T>
	struct Type
	{
		std::map<std::string, T> resources;

		Type(const std::string& folder)
			: resources()
		{
			for (auto& f : std::filesystem::directory_iterator("resources/" + folder))
			{
				auto path = f.path();
				T resource;
				resource.loadFromFile(path.string());
				resources[path.stem()] = resource;
			}
		}

		T& operator[](const std::string& name)
		{
			return resources[name];
		}
	};

public:
	Type<sf::Texture> textures;
	Type<sf::Image> images;
	Type<Text> texts;
	Type<Text> levels;
	Type<sf::Font> fonts;

	Resources();
};