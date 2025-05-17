#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"

class Map
{
private:
	sf::Texture tileSheetTexture;
	
	// Lookup table
	Tile* tiles; // Pointer to a future array

	int tileWidth;
	int tileHeight;

	int totalTiles;
	int totalTilesX;
	int totalTilesY;

	// Static : only one variable of this name will ever exist
	static const int map_size = 25;
	int map_width;
	int map_height;

	int mapTileIds[map_size] =
	{
		10, 10, 10, 10, 10,
		10,  0,  1,  2, 10,
		10,  6,  7,  8, 10,
		10,  6,  7,  8, 10,
		10, 12, 13, 14, 10
	};

	sf::Sprite mapSprites[map_size];

public:
	Map();
	~Map();

	void initialize();
	void load();
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);
};

