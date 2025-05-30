#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(Grid& grid) :
	grid(nullptr), lineThickness(0), isMouseOnGrid(false)
{
	this->grid = &grid;

	lineThickness = this->grid->getLineThickness();
	gridPosition = this->grid->getPosition();
	gridScale = this->grid->getScale();
	tileSize = this->grid->getCellSize();
	totalLines = this->grid->getTotalLines();
	totalCells = this->grid->getTotalCells();
}
MouseTile::~MouseTile()
{
}

void MouseTile::initialize()
{
}

void MouseTile::load()
{
	tileSheet.loadFromFile("../rpg-game/assets/tilesheets/overworld_tiles.png");
	tile.setTexture(tileSheet);
	tile.setTextureRect(sf::IntRect(1 + (tileSize.x + 1) * 0, 1 + (tileSize.y + 1) * 0, tileSize.x, tileSize.y));
	tile.setScale(sf::Vector2f(2, 2));
}
void MouseTile::update(float deltaTime, const sf::Vector2f& mousePosition)
{
	// Find which tile index on grid to use
	tileGridIndex.x = (mousePosition.x - gridPosition.x) / ((tileSize.x * gridScale.x + lineThickness)); // Lose decimal points to get rid of the remainder
	tileGridIndex.y = (mousePosition.y - gridPosition.y) / ((tileSize.y * gridScale.y + lineThickness));

	// Scale up to the tile position
	tileGridPosition.x = (tileGridIndex.x * (tileSize.x + 1) * gridScale.x) + lineThickness;
	tileGridPosition.y = (tileGridIndex.y * (tileSize.y + 1) * gridScale.y) + lineThickness;

	if ((tileGridIndex.x >= 0 && tileGridIndex.y >= 0) && (tileGridIndex.x < totalCells.x && tileGridIndex.y < totalCells.y))
	{
		isMouseOnGrid = true;
	}
	else if (isMouseOnGrid)
	{
		isMouseOnGrid = false;
	}

	tile.setPosition(sf::Vector2f(tileGridPosition.x, tileGridPosition.y) + gridPosition);
}
void MouseTile::draw(sf::RenderWindow& window)
{
	window.draw(tile);
}

bool MouseTile::isMouseClickedOnTile(sf::Vector2f& tileIndex, sf::Vector2f& tilePosition, sf::Vector2f& mousePosition) const
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isMouseOnGrid)
	{
		tileIndex = sf::Vector2f(tileGridIndex.x, tileGridIndex.y); // Modify original variable
		tilePosition = sf::Vector2f(tileGridPosition.x, tileGridPosition.y) + gridPosition;

		return true;
	}

	return false;
}
