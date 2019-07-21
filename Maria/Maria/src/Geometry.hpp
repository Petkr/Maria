#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

using Vector = sf::Vector2f;
using Rectangle = sf::FloatRect;

bool empty(const Vector& v);

Vector size(const Rectangle& r);
Vector position(const Rectangle& r);