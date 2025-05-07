#pragma once
#include "Squid.h"

class Player
{
private:
	sf::Texture texture;
	sf::Vector2f size;
	float speed;

	sf::Vector2f bulletDirection;
	float bulletSpeed;
	std::vector<sf::RectangleShape> bullets;
	
public:
	sf::RectangleShape boundingBox;
	sf::Sprite sprite;

public:
	void initialize();
	void load();
	void update(float deltaTime, Squid& squid);
	void draw(sf::RenderWindow& window);
};

