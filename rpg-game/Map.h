#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "MapLoader.h"
#include "MapData.h"

class Map
{
private:
	MapLoader mapLoader;
	MapData md;

	sf::Texture tileSheetTexture;
	
	// Lookup table
	Tile* tiles; // Pointer to a future array

	int totalTiles;
	int totalTilesX;
	int totalTilesY;

	// Static : only one variable of this name will ever exist
	int map_width;
	int map_height;

	// Tiles that are displayed
	sf::Sprite* mapSprites = nullptr;

public:
	Map();
	~Map();

	void initialize();
	void load(std::string filename);
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);
};

