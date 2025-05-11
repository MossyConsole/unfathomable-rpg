#pragma once
#include <SFML/Graphics.hpp>

class Map
{
private:
	sf::Texture tileSheetTexture;
	sf::Sprite sprites[10];

	int tileWidth;
	int tileHeight;

	int totalTilesX;
	int totalTilesY;
public:
	Map();
	~Map();

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
};

