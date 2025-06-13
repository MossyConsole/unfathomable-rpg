#pragma once
#include <SFML/Graphics.hpp>

// In C++, structs and classes are basically the same. But structs are public by default, and classes are private
// Structs shouldn't contain functions; only data
struct Tile
{
	sf::Texture* texture = nullptr; // Must initialize pointers
	sf::Vector2f position;
	bool hasCollision = false;
	bool hasInteraction = false;

	int id = -1;
};

