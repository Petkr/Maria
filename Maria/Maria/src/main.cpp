#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "UI.hpp"
#include "Textures.hpp"

int main()
{
	Textures::Init();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Maria");
	window.setFramerateLimit(60);
	
	{
		sf::Image icon;
		icon.loadFromFile("resources/icon.png");
		window.setIcon(32, 32, icon.getPixelsPtr());
	}

	sf::RectangleShape shape;
	{
		auto mario_texture = Textures::Get(Textures::mario);
		shape.setSize(Vector(mario_texture->getSize()));
		shape.setPosition(sf::Vector2f(50, 50));
		shape.setTexture(mario_texture);
	}

	sf::Font font;
	font.loadFromFile("resources/font.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Magenta);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Key::W:
					text.setString("W");
					break;
				case sf::Keyboard::A:
					text.setString("A");
					break;
				case sf::Keyboard::D:
					text.setString("D");
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				default:
					break;
				}
				break;
			case sf::Event::MouseButtonPressed:
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Button::Left:
					text.setString("Klik");
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		window.clear();
		window.draw(shape);
		window.draw(text);
		window.display();
	}

	return 0;
}