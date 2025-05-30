#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"

#define MAP_SIZE (24 * 16)

class Map
{
private:
	MouseTile& mouseTile;
	sf::Sprite* mapSprites;

public:
	Map(MouseTile& mouseTile);
	~Map();

	void initialize();
	void load();
	void update(double deltaTime, sf::Vector2f& mousePosition);
	void draw(sf::RenderWindow& window);
};

