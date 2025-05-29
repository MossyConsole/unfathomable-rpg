#include "MouseTile.h"

MouseTile::MouseTile() :
	grid(nullptr), lineThickness(0)
{

}
MouseTile::~MouseTile()
{

}

void MouseTile::initialize(Grid& grid)
{
	this->grid = &grid;

	lineThickness = this->grid->getLineThickness();
	gridPosition = this->grid->getPosition();
	gridScale = this->grid->getScale();
	tileSize = this->grid->getCellSize();
}
void MouseTile::load()
{
	tileSheet.loadFromFile("../rpg-game/assets/tilesheets/overworld_tiles.png");
	tile.setTexture(tileSheet);
	tile.setTextureRect(sf::IntRect(1 + (tileSize.x + 1) * 0, 1 + (tileSize.y + 1) * 0, tileSize.x, tileSize.y));
	tile.setScale(sf::Vector2f(2, 2));
}
void MouseTile::update(float deltaTime, sf::Vector2f mousePosition)
{
	
	
	// Find which tile index on grid to use
	int index_x = (mousePosition.x - gridPosition.x) / ((tileSize.x * gridScale.x + lineThickness)); // Lose decimal points to get rid of the remainder
	int index_y = (mousePosition.y - gridPosition.y) / ((tileSize.y * gridScale.y + lineThickness));

	// Scale up to the tile position
	int x = (index_x * (tileSize.x + 1) * gridScale.x) + lineThickness;
	int y = (index_y * (tileSize.y + 1) * gridScale.y) + lineThickness;

	tile.setPosition(sf::Vector2f(x, y) + gridPosition);
}
void MouseTile::draw(sf::RenderWindow& window)
{
	window.draw(tile);
}