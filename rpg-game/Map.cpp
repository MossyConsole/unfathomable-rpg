#include "Map.h"
#include <iostream>

Map::Map() :
    tileWidth(16), tileHeight(16),
    totalTilesX(0), totalTilesY(0)
{

}

Map::~Map()
{

}

void Map::initialize()
{

}
void Map::load()
{
    if (tileSheetTexture.loadFromFile("assets/tiles/overworld_tiles.png"))
    {
        totalTilesX = (tileSheetTexture.getSize().x - 1) / (tileWidth + 1);
        totalTilesY = (tileSheetTexture.getSize().y - 1) / (tileHeight + 1);

        // std::cout << "Width: " << totalTilesX << std::endl;
        // std::cout << "Height: " << totalTilesY << std::endl;

        for (size_t i = 0; i < 10; i++)
        {
            sprites[i].setTexture(tileSheetTexture);
            sprites[i].setTextureRect(sf::IntRect(1 + (tileWidth + 1) * 4, 1 + (tileHeight + 1) * 1, tileWidth, tileHeight));
            sprites[i].setScale(sf::Vector2f(4, 4));
            sprites[i].setPosition(sf::Vector2f(4 * tileWidth * i, 0));
        }
    }
    else
    {
        std::cout << "World Image Failed to Load";
    }
}
void Map::update(float deltaTime)
{
 
}
void Map::draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 10; i++)
        window.draw(sprites[i]);
}
