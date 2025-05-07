#pragma once
#include <SFML/Graphics.hpp>
#include "Tools.h"

class Squid
{
private:
	sf::Texture texture;
	sf::Vector2f size;
	float speed;
	
public:
	sf::RectangleShape boundingBox;
	sf::Sprite sprite;

public:
	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};

