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
		sf::Vector2f gridPosition;
		sf::Vector2i gridScale;
		sf::Vector2i tileSize;

	public:
		MouseTile();
		~MouseTile();

		void initialize(Grid& grid);
		void load();
		void update(float deltaTime, sf::Vector2f mousePosition);
		void draw(sf::RenderWindow& window);

};

