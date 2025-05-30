#pragma once
#include <SFML/Graphics.hpp>
#include "Grid.h"

class MouseTile
{
private:
	sf::Texture tileSheet;
	sf::Sprite tile;
		
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

public:
	MouseTile(Grid& grid);
	~MouseTile();

	void initialize();
	void load();
	void update(float deltaTime, const sf::Vector2f& mousePosition);
	void draw(sf::RenderWindow& window);

	bool isMouseClickedOnTile(sf::Vector2f& tileIndex, sf::Vector2f& tilePosition, sf::Vector2f& mousePosition) const; // Function has to be const to be passed by reference
	inline const sf::Sprite& getSprite() { return tile;  }
};

