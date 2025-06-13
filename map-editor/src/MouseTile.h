#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "TilesheetDisplay.h"

class MouseTile
{
private:
	enum key { W, A, S, D };
	key keyPressed;

	sf::Texture tileSheet;
	sf::Sprite tile;

	sf::RectangleShape selection;
		
	Grid* grid;
	int lineThickness;
	sf::Vector2i totalLines;
	sf::Vector2i totalCells;
	sf::Vector2f gridPosition;
	sf::Vector2i gridScale;
	sf::Vector2i tileSize;

	sf::Vector2i tileGridIndex;
	sf::Vector2i tileGridPosition;
	sf::Vector2i tileWindowPosition;
	bool isMouseOnGrid;

	sf::Vector2i currentTileID;

	sf::Sprite* standardTiles;
	sf::Vector2i tilesheetSize;

	bool pressed;
	bool wasPressed;
	bool released;

	sf::Vector2f tileDisplayPosition;

public:
	MouseTile(Grid& grid);
	~MouseTile();

	void initialize();
	void load(TilesheetDisplay& tsDz);
	void update(float deltaTime, const sf::Vector2f& mousePosition);
	void draw(sf::RenderWindow& window);

	bool isMouseClickedOnTile(sf::Vector2f& tileIndex, sf::Vector2f& tilePosition, sf::Vector2f& mousePosition) const; // Function has to be const to be passed by reference
	inline const sf::Sprite& getSprite() { return tile; }
	inline const sf::Texture getTilesheet() { return tileSheet; }
	inline const sf::Sprite* getStandardTiles() { return standardTiles; }
	inline const sf::Vector2i getTilesheetSize() { return tilesheetSize; }
	inline const sf::Vector2i getCurrentTileID() { return currentTileID; }
};

