#include "Map.h"
#include <iostream>

Map::Map() :
    totalTilesX(0), totalTilesY(0), totalTiles(0),
    map_width(0), map_height(0), tiles(nullptr), mapTileCount(0)
{
}

Map::~Map()
{ 
    delete[] mapSprites;
    delete[] tiles;
    delete[] collisionRects;
    delete[] interactionRects;
}

void Map::initialize()
{
}

void Map::load(std::string filename, const int level, const Environment environment)
{
    mapLoader.load(filename, md);
    mapSprites = new customSprite[md.getDataLength()];

    map_width = md.getMapWidth();
    map_height = md.getMapHeight();

    if (tileSheetTexture.loadFromFile(md.getTilesheet()))
    {
        totalTilesX = (tileSheetTexture.getSize().x - 1) / (md.getTileWidth() + 1);
        totalTilesY = (tileSheetTexture.getSize().y - 1) / (md.getTileHeight() + 1);

        // std::cout << "TS Width: " << totalTilesX << std::endl;
        // std::cout << "TS Height: " << totalTilesY << std::endl;

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
                tiles[i].position = sf::Vector2f(1 + x * (1 + md.getTileWidth()), 1 + y * (1 + md.getTileHeight()));

                // Overworld
                if (environment == OVERWORLD)
                {
                    const int collisions = 18;
                    const int interactions = 2;

                    const int t_width = md.getTileWidth();
                    const int t_height = md.getTileHeight();
                    const int scaleX = md.getScaleX();
                    const int scaleY = md.getScaleY();
                    
                    mapTileCount = md.getMapHeight() * md.getMapWidth();

                    const int collisionTiles[collisions] = {11, 15, 16, 18, 19, 20, 21, 22, 24, 26, 27, 28, 30, 31, 32, 33, 34, 35};
                    const int interactionTiles[interactions] = {4, 5};

                    collisionRects = new std::vector<sf::RectangleShape>(mapTileCount);
                    interactionRects = new std::vector<sf::RectangleShape>(mapTileCount);

                    std::cout << "I: " << i << std::endl;

                    for (size_t j = 0; j < collisions; j++)
                    {
                        if (collisionTiles[j] == i)
                        {
                            tiles[i].hasCollision = true;
                        }
                    }
                    for (size_t j = 0; j < interactions; j++)
                    {
                        if (interactionTiles[j] == i)
                        {
                            tiles[i].hasInteraction = true;
                        }
                     }
                }
                /*
                else if (environment == CAVES)
                {
                    const int collisions = 13;
                    const int interactions = 2;

                    int collisionTiles[collisions] = { 0, 1, 2, 4, 6, 8, 9, 10, 12, 13, 14, 15, 16 };
                    int interactionTiles[interactions] = { 18, 19 };

                    for (size_t j = 0; j < collisions; j++)
                    {
                        if (collisionTiles[j] == i)
                        {
                            tiles[i].collision = true;
                        }
                    }

                    for (size_t j = 0; j < interactions; j++)
                    {
                        if (interactionTiles[j] == i)
                        {
                            tiles[i].interaction = true;
                        }
                    }
                    
                }
                */
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

            mapSprites[i].sprite.setTexture(*tiles[index].texture);

            mapSprites[i].sprite.setTextureRect(sf::IntRect(
                tiles[index].position.x, 
                tiles[index].position.y,
                md.getTileWidth(),
                md.getTileHeight()));

            // mapSprites[i].sprite.setTexture(tileSheetTexture);
            mapSprites[i].sprite.setPosition(sf::Vector2f(x * md.getScaleX() * md.getTileWidth(), y * md.getScaleY() * md.getTileHeight()));
            mapSprites[i].sprite.setScale(sf::Vector2f(md.getScaleX(), md.getScaleY()));

            if (tiles[index].hasCollision)
            {
                // std::cout << "Tile " << index << " has Collision." << std::endl;

                mapSprites[i].hasCollision = true;

                (*collisionRects)[i].setPosition(mapSprites[i].sprite.getPosition());
                (*collisionRects)[i].setFillColor(sf::Color::Color(255, 0, 0, 100));
                (*collisionRects)[i].setSize(sf::Vector2f(mapSprites[i].sprite.getGlobalBounds().width, mapSprites[i].sprite.getGlobalBounds().height));
            }

            if (tiles[index].hasInteraction)
            {
                // std::cout << "Tile " << index << " has Collision." << std::endl;

                mapSprites[i].hasInteraction = true;

                (*interactionRects)[i].setPosition(mapSprites[i].sprite.getPosition());
                (*interactionRects)[i].setFillColor(sf::Color::Color(0, 0, 255, 100));
                (*interactionRects)[i].setSize(sf::Vector2f(mapSprites[i].sprite.getGlobalBounds().width, mapSprites[i].sprite.getGlobalBounds().height));
            }

            // std::cout << "I: " << i << std::endl;
        }
    }
}

void Map::update(double deltaTime)
{
 
}

void Map::draw(sf::RenderWindow& window)
{
    for (size_t i = 0; i < md.getDataLength(); i++)
    {
        window.draw(mapSprites[i].sprite);

        if (mapSprites[i].hasCollision)
        {
            // window.draw((*collisionRects)[i]);
        }
        if (mapSprites[i].hasInteraction)
        {
            // window.draw((*interactionRects)[i]);
        }
    }
}
