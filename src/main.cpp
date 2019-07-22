#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "UI.hpp"
#include "Resources.hpp"

int main()
{
	Resources resources;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Maria");
	window.setFramerateLimit(60);
	
	window.setIcon(32, 32, resources.images["icon"].getPixelsPtr());

	sf::RectangleShape shape;
	{
		auto mario_texture = &resources.textures["mario"];
		shape.setSize(Vector(mario_texture->getSize()));
		shape.setPosition(sf::Vector2f(50, 50));
		shape.setTexture(mario_texture);
	}

	sf::Text text;
	text.setFont(resources.fonts["font"]);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Magenta);

	sf::Text textik;
	textik.setFont(resources.fonts["font"]);
	textik.setCharacterSize(10);
	textik.setFillColor(sf::Color::White);
	textik.setString(resources.texts["help"]);

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
		window.draw(textik);
		window.display();
	}

	return 0;
}