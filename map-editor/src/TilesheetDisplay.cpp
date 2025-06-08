#include "TilesheetDisplay.h"

void TilesheetDisplay::initialize()
{
}

void TilesheetDisplay::load()
{
	tilesheet.loadFromFile("../rpg-game/assets/tilesheets/overworld_tiles.png");
	sprite.setTexture(tilesheet);
	sprite.setScale(2, 2);
	sprite.setPosition(sf::Vector2f(800, 60));
}

void TilesheetDisplay::update(double deltaTime)
{
}

void TilesheetDisplay::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
