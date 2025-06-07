#pragma once
#include "Squid.h"
#include "Bullet.h"

class Player
{
private:
	sf::Texture texture;
	sf::Vector2f size;
	float speed;

	std::vector<Bullet> bullets;

	float maxFireRate;
	float fireRateTimer;
	
public:
	sf::RectangleShape boundingBox;
	sf::Sprite sprite;

public:
	Player();

	void initialize();
	void load();
	void update(float deltaTime, Squid& squid, sf::Vector2f& mousePosition);
	void draw(sf::RenderWindow& window);
};

