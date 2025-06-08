#include "Map.h"
#include <iostream>

Map::Map() :
    totalTilesX(0), totalTilesY(0), totalTiles(0),
    map_width(5), map_height(5), tiles(nullptr)
{
}

Map::~Map()
{ 
    delete[] mapSprites;
    delete[] tiles;
}

void Map::initialize()
{
}
void Map::load(std::string filename)
{
    mapLoader.load(filename, md);
    mapSprites = new sf::Sprite[md.getDataLength()];

    if (tileSheetTexture.loadFromFile(md.getTilesheet()))
    {
        totalTilesX = (tileSheetTexture.getSize().x - 1) / (md.getTileWidth() + 1);
        totalTilesY = (tileSheetTexture.getSize().y - 1) / (md.getTileHeight() + 1);

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
                tiles[i].position = sf::Vector2i(1 + x * (1 + md.getTileWidth()), 1 + y * (1 + md.getTileHeight()));
            }
        }
    }
    else
    {
        std::cout << "World Image Failed to Load";
    }

    // Initialize the tile sprites
    for (size_t y = 0; y < map_height; y++)
    {
        for (size_t x = 0; x < map_width; x++)
        {
            int i = x + y * map_width;

            int index = md.getData()[i];

            mapSprites[i].setTexture(*tiles[index].texture);

            mapSprites[i].setTextureRect(sf::IntRect(
                tiles[index].position.x, 
                tiles[index].position.y,
                md.getTileWidth(),
                md.getTileHeight()));

            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setPosition(sf::Vector2f(x * md.getScaleX() * md.getTileWidth(), y * md.getScaleY() * md.getTileHeight()));
            mapSprites[i].setScale(sf::Vector2f(md.getScaleX(), md.getScaleY()));
        }
    }
}
void Map::update(double deltaTime)
{
 
}
void Map::draw(sf::RenderWindow& window)
{ 
    for (size_t i = 0; i < md.getDataLength(); i++)
        window.draw(mapSprites[i]);
}
