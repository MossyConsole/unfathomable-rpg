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

	int mapTileIds[25] =
	{
		10, 10, 10, 10, 10,
		10,  0,  1,  2, 10,
		10,  6,  7,  8, 10,
		10,  6,  7,  8, 10,
		10, 12, 13, 14, 10
	};

	sf::Sprite mapSprites[25];

public:
	Map();
	~Map();

	void initialize();
	void load();
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);
};

