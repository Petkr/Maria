#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "UI.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	UI ui;
	ui.buttons.push_back({UI::margin, UI::margin, 100, 100});
	sf::RectangleShape s;
	sf::RectangleShape shape(sf::Vector2f(25, 25));
	shape.setPosition(sf::Vector2f(50, 50));

	sf::Texture texture;
	
	texture.loadFromFile("resources/mario.png");

	shape.setTexture(&texture);

	int x = 0;
	sf::Font font;
	font.loadFromFile("resources/font.ttf");
	
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Magenta);

	sf::Clock clock;
	while (window.isOpen())
	{
		clock.restart();
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
				}
				break;
			}
			case sf::Event::MouseButtonPressed:
				switch (event.mouseButton.button)
				{
				case sf::Mouse::Button::Left:
					for (auto& button : ui.buttons)
						button.Check();
					break;
				}
				break;
		}

		window.clear();
		window.draw(shape);
		window.draw(text);
		window.display();

		std::this_thread::sleep_for(std::chrono::milliseconds(std::max(clock.getElapsedTime().asMicroseconds() - 16667, 0)));
	}

	return 0;
}