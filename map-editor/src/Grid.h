#pragma once
#include <SFML/Graphics.hpp>

class Grid
{
private:
	sf::RectangleShape* hlines;
	sf::RectangleShape* vlines;
	sf::RectangleShape globalBounds;

	sf::Vector2f position;

	int lineThickness;

	sf::Vector2i scale;
	sf::Vector2i totalCells;
	sf::Vector2i cellSize;
	sf::Vector2i totalLines;
	sf::Color color;

public:

	Grid(const sf::Vector2f& position,
		const sf::Vector2i& cellSize,
		const sf::Vector2i& totalCells,
		const sf::Vector2i& scale,
		const int lineThickness,
		const sf::Color& color);
	~Grid();

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	inline sf::Vector2f getPosition() { return position; }
	inline int getLineThickness() { return lineThickness; }
	inline sf::Vector2i getScale() { return scale; }
	inline sf::Vector2i getCellSize() { return cellSize; }
	inline sf::Vector2i getTotalLines() { return totalLines; }
	inline sf::Vector2i getTotalCells() { return totalCells; }
	inline sf::RectangleShape getGlobalBounds() { return globalBounds; }
};

