#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

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
				if (event.key.code == sf::Keyboard::Escape)
				{
					text.setString(std::to_string(++x));
				}
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