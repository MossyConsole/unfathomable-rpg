#pragma once
#include <SFML/Graphics.hpp>
#include "MouseTile.h"
#include "Grid.h"
#include "Tile.h"

#define MAP_SIZE (24 * 16)

class Map
{
private:
	MouseTile& mouseTile;
	sf::Sprite* mapSprites;

	Grid* grid;
	sf::Vector2i totalCells;


	
public:
	Map(MouseTile& mouseTile, Grid& grid);
	~Map();

	void initialize();
	void load(MouseTile& mouseTile);
	void update(double deltaTime, sf::Vector2f& mousePosition);
	void draw(sf::RenderWindow& window);
};

