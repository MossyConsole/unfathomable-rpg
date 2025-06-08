#include "MouseTile.h"
#include <iostream>

MouseTile::MouseTile(Grid& grid) :
	isMouseOnGrid(false), tileGridIndex(sf::Vector2i(0, 0)), tileGridPosition(sf::Vector2f(0, 0)), currentTileID(sf::Vector2i(3, 0)),
	standardTiles(nullptr), tilesheetSize(sf::Vector2i(0, 0)), wasPressed(false), pressed(false), released(false), keyPressed(W)
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
	delete[] standardTiles;
}

void MouseTile::initialize()
{
}

void MouseTile::load(TilesheetDisplay& tsD)
{
	int scale = 2;

	tileSheet.loadFromFile("../rpg-game/assets/tilesheets/overworld_tiles.png");
	tile.setTexture(tileSheet);
	tile.setTextureRect(sf::IntRect(1 + (tileSize.x + 1) * currentTileID.x, 1 + (tileSize.y + 1) * currentTileID.y, tileSize.x, tileSize.y));
	tile.setScale(sf::Vector2f(scale, scale));

	selection = sf::RectangleShape(sf::Vector2f(tileSize.x, tileSize.y));
	selection.setFillColor(sf::Color::Color(78, 208, 26, 100));
	selection.setOutlineThickness(1);
	selection.setOutlineColor(sf::Color::Color(78, 208, 26));

	tileDisplayPosition = tsD.getSpritePosition();
	sf::Vector2f offsetPos = sf::Vector2f((1 + (tileSize.x + 1) * currentTileID.x) * scale, (1 + (tileSize.y + 1) * currentTileID.y) * scale);
	selection.setPosition(tileDisplayPosition + offsetPos);
	selection.setScale(sf::Vector2f(scale, scale));

	tilesheetSize.x = (tileSheet.getSize().x - 1) / (grid->getCellSize().x + 1);
	tilesheetSize.y = (tileSheet.getSize().y - 1) / (grid->getCellSize().y + 1);
	int const size = tilesheetSize.x * tilesheetSize.y;
	// std::cout << "SIZE: " << size << std::endl;

	standardTiles = new sf::Sprite[size];

	int tile_size_x = grid->getCellSize().x;
	int tile_size_y = grid->getCellSize().y;

	for (size_t y = 0; y < tilesheetSize.y; y++)
	{
		for (size_t x = 0; x < tilesheetSize.x; x++)
		{
			int i = y * tilesheetSize.x + x;
			standardTiles[i].setTexture(tileSheet);
			standardTiles[i].setTextureRect(sf::IntRect(1 + (tile_size_x + 1) * x, 1 + (tile_size_y + 1) * y, tile_size_x, tile_size_y));
			standardTiles[i].setScale(sf::Vector2f(2, 2));
		}
	}
}
void MouseTile::update(float deltaTime, const sf::Vector2f& mousePosition)
{
	// Check if mouse is on grid
	if ((gridPosition.x < mousePosition.x && (gridPosition.x + grid->getGlobalBounds().getSize().x) > mousePosition.x) 
		&& (gridPosition.y < mousePosition.y && (gridPosition.y + grid->getGlobalBounds().getSize().y) > mousePosition.y))
	{
		isMouseOnGrid = true;

		// Find which tile index on grid to use
		tileGridIndex.x = (mousePosition.x - gridPosition.x) / ((tileSize.x * gridScale.x + lineThickness)); // Lose decimal points to get rid of the remainder
		tileGridIndex.y = (mousePosition.y - gridPosition.y) / ((tileSize.y * gridScale.y + lineThickness));

		// Scale up to the tile position
		tileGridPosition.x = tileGridIndex.x * (tileSize.x * gridScale.x + lineThickness) + lineThickness;
		tileGridPosition.y = tileGridIndex.y * (tileSize.y * gridScale.y + lineThickness) + lineThickness;

		tile.setPosition(sf::Vector2f(tileGridPosition.x, tileGridPosition.y) + gridPosition);
	}
	else if (isMouseOnGrid)
	{
		isMouseOnGrid = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		keyPressed = W;
		pressed = true;
		wasPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		keyPressed = A;
		pressed = true;
		wasPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		keyPressed = S;
		pressed = true;
		wasPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		keyPressed = D;
		pressed = true;
		wasPressed = true;
	}
	else if (wasPressed)
	{
		pressed = false;
		released = true;
	}

	if (wasPressed && released)
	{
		wasPressed = false;
		released = false;

		switch (keyPressed)
		{
		case W:
			if (currentTileID.y > 0)
			{
				currentTileID.y--;
			}
			else
			{
				currentTileID.y = tilesheetSize.y - 1;
			}
			break;
		case A:
			if (currentTileID.x > 0)
			{
				currentTileID.x--;
			}
			else
			{
				currentTileID.x = tilesheetSize.x - 1;
			}
			break;
		case S:
			if (currentTileID.y < tilesheetSize.y - 1)
			{
				currentTileID.y++;
			}
			else
			{
				currentTileID.y = 0;
			}
			break;
		case D:
			if (currentTileID.x < tilesheetSize.x - 1)
			{
				currentTileID.x++;
			}
			else
			{
				currentTileID.x = 0;
			}
			break;
		}
		

		int i = currentTileID.y * tilesheetSize.x + currentTileID.x;

		// std::cout << "New tileID.x : " << currentTileID.x << std::endl;
		// std::cout << "New tileID.y : " << currentTileID.y << std::endl;
		
		// std::cout << "New tile # : " << i << std::endl;

		tile = standardTiles[i];

		// Update Selection on TileDisplay
		sf::Vector2f offsetPos = sf::Vector2f((1 + (tileSize.x + 1) * currentTileID.x) * 2, (1 + (tileSize.y + 1) * currentTileID.y) * 2);
		selection.setPosition(tileDisplayPosition + offsetPos);
	}
}
void MouseTile::draw(sf::RenderWindow& window)
{
	if (isMouseOnGrid)
	{
		window.draw(tile);
	}

	window.draw(selection);
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
