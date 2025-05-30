#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"

#define MAP_SIZE (24 * 16)

class Map
{
private:
	MouseTile mouseTile;
	sf::Sprite* mapSprites;

public:
	Map(const MouseTile& mouseTile);
	~Map();

	void initialize();
	void load(std::string filename);
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);

private:
	void onGridClick(int i);
};

