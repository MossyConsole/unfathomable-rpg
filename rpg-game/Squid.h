#pragma once
#include <SFML/Graphics.hpp>

class Squid
{
private:
	sf::Texture texture;

public:
	sf::Sprite sprite;

public:
	// Call once
	void initialize();
	void load();
	// Call every frame
	void update();
	void draw(sf::RenderWindow& window);
};
