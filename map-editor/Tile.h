#pragma once
#include <SFML/Graphics.hpp>

// In C++, structs and classes are basically the same. But structs are public by default, and classes are private
// Structs shouldn't contain functions; only data
struct Tile
{
	sf::Texture* texture = nullptr;
	sf::Vector2i position;

	int id = -1;
};