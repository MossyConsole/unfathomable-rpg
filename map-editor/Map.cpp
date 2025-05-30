#include "Map.h"

Map::Map(const MouseTile& mouseTile):
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
void Map::load(std::string filename)
{

}
void Map::update(double deltaTime)
{

}
void Map::draw(sf::RenderWindow& window) 
{
	for (size_t i = 0; i < MAP_SIZE; i++)
		window.draw(mapSprites[i]);
}

void Map::onGridClick(int i)
{
}
