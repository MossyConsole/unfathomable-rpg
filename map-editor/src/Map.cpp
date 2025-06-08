#include "Map.h"
#include <iostream>

Map::Map(MouseTile& mouseTile, Grid& grid):
	mouseTile(mouseTile), mapSprites(nullptr)
{
	this->grid = &grid;

	totalCells = grid.getTotalCells();
}
Map::~Map()
{
	delete[] mapSprites;
	
}

void Map::initialize()
{
}
void Map::load(MouseTile& mouseTile)
{
	mapSprites = new sf::Sprite[MAP_SIZE];
}
void Map::update(double deltaTime, sf::Vector2f& mousePosition)
{
	sf::Vector2f tileIndex, tilePosition;
	int i = 0;

	if (mouseTile.isMouseClickedOnTile(tileIndex, tilePosition, mousePosition))
	{
		i = tileIndex.x + tileIndex.y * totalCells.x;
		std::cout << tilePosition.x << " " << tilePosition.y << "\t" << i << std::endl;

		// tileIDs[i] = i;
		mapSprites[i] = sf::Sprite(mouseTile.getSprite());
	}
}
void Map::draw(sf::RenderWindow& window) 
{
	for (size_t i = 0; i < MAP_SIZE; i++)
		window.draw(mapSprites[i]);
}
