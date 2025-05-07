#pragma once
#include <SFML/Graphics.hpp>

class Tools
{
public:
	static sf::Vector2f normalizeVector2f(sf::Vector2f vector);
	static bool checkRectCollision(sf::FloatRect rect_A, sf::FloatRect rect_B);
};

