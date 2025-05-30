#include "Map.h"
#include <iostream>

Map::Map(MouseTile& mouseTile):
	mouseTile(mouseTile), mapSprites(nullptr)
{

}
Map::~Map()
{
	delete[] mapSprites;
}

void Map::initialize()
{
	mapSprites = new sf::Sprite[MAP_SIZE];
}
void Map::load()
{

}
void Map::update(double deltaTime, sf::Vector2f& mousePosition)
{
	sf::Vector2f tilePosition;

	if (mouseTile.isMouseClickedOnTile(tilePosition, mousePosition))
	{
		std::cout << tilePosition.x << " " << tilePosition.y << std::endl;
	}
}
void Map::draw(sf::RenderWindow& window) 
{
	for (size_t i = 0; i < MAP_SIZE; i++)
		window.draw(mapSprites[i]);
}
