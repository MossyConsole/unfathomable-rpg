#pragma once
#include <SFML/Graphics.hpp>
#include <core/MapData.h>
#include "Tile.h"
#include "MapLoader.h"

class Map
{
public:
	enum Environment {
		OVERWORLD,
		CAVES
	};

	// Tiles that are displayed
	struct customSprite {
		sf::Sprite sprite;

		bool hasCollision = false;
		bool hasInteraction = false;
	};

private:
	MapLoader mapLoader;
	MapData md;

	sf::Texture tileSheetTexture;

	std::vector<sf::RectangleShape>* collisionRects;
	std::vector<sf::RectangleShape>* interactionRects;
	
	// Lookup table
	Tile* tiles; // Pointer to a future array

	int totalTiles;
	int totalTilesX;
	int totalTilesY;

	// Static : only one variable of this name will ever exist
	int map_width;
	int map_height;

	customSprite* mapSprites = nullptr;
	int mapTileCount;

public:
	Map();
	~Map();

	void initialize();
	void load(std::string filename, const int level , const Environment environment);
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);

	inline customSprite* getMapSprites() { return mapSprites; }
	inline int getMapTileCount() { return mapTileCount; }
};

