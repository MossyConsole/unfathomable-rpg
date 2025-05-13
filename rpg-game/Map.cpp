#include "Map.h"
#include <iostream>

Map::Map() :
    tileWidth(16), tileHeight(16),
    totalTilesX(0), totalTilesY(0), totalTiles(0)
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

        totalTiles = totalTilesX * totalTilesY;

        // Whenever you allocate memory for a pointer, you use the "new" keyword
        tiles = new Tile[totalTiles]; // Create the array of size [X * Y] and assign this pointer to it

        // Initialize the array of tile textures
        for (size_t y = 0; y < totalTilesY; y++)
        {
            for (size_t x = 0; x < totalTilesX; x++)
            {
                int i = x + y * totalTilesX;

                tiles[i].id = i;
                tiles[i].texture = &tileSheetTexture;
                tiles[i].position = sf::Vector2i(1 + x * (1 + tileWidth), 1 + y * (1 + tileHeight));
            }
        }
    }
    else
    {
        std::cout << "World Image Failed to Load";
    }

    // Initialize the tile sprites
    for (size_t y = 0; y < 5; y++)
    {
        for (size_t x = 0; x < 5; x++)
        {
            int i = x + y * 5;

            int index = mapTileIds[i];

            mapSprites[i].setTexture(*tiles[index].texture);

            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x, 
                tiles[index].position.y,
                tileWidth, 
                tileHeight));

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setPosition(sf::Vector2f(x * 4 * tileWidth, y * 4 * tileHeight));
            mapSprites[i].setScale(sf::Vector2f(4, 4));
        }
    }
}
void Map::update(double deltaTime)
{
 
}
void Map::draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < 25; i++)
        window.draw(mapSprites[i]);
}
