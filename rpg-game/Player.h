#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Squid.h"

class Player
{
private:
	sf::Texture texture;

	std::vector<sf::RectangleShape> bullets;
	sf::Vector2f bulletDirection;
	float bulletSpeed = 0.1f;

public:
	sf::Sprite sprite;

public:
	// Call once
	void initialize();
	void load();
	// Call every frame
	void update(Squid& squid);
	void draw(sf::RenderWindow& window);
};

