#pragma once
#include <SFML/Graphics.hpp>
#include "Tools.h"

class Squid
{
private:
	sf::Texture texture;
	sf::Vector2f size;
	float speed;

	sf::Text healthText; // Sprite
	sf::Font font; // Texture
	
public:
	sf::RectangleShape boundingBox;
	sf::Sprite sprite;

	int health = 100;

public:
	void changeHP(float difference);
	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};

