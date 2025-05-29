#include "Grid.h"

Grid::Grid(const sf::Vector2f& position,
	const sf::Vector2i& cellSize,
	const sf::Vector2i& totalCells,
	const sf::Vector2i& scale,
	const int lineThickness,
	const sf::Color& color) :
	position(position), scale(scale), totalCells(totalCells), cellSize(cellSize), lineThickness(lineThickness), color(color)
{
	// Create arrays of lines on the heap
	totalLines = sf::Vector2i(this->totalCells + sf::Vector2i(1, 1));
	hlines = new sf::RectangleShape[totalLines.y];
	vlines = new sf::RectangleShape[totalLines.x];
}

Grid::~Grid()
{
	delete[] hlines;
	delete[] vlines;
}

void Grid::initialize()
{
	int horizontalLineLength = totalCells.x * (cellSize.x * scale.x + lineThickness) + lineThickness;
	int verticalLineLength = totalCells.y * (cellSize.y * scale.y + lineThickness);

	for (size_t i = 0; i < totalLines.y; i++)
	{
		hlines[i].setSize(sf::Vector2f(horizontalLineLength, lineThickness));
		hlines[i].setPosition(position + sf::Vector2f(0, i * (cellSize.y * scale.x + lineThickness) ));
		hlines[i].setFillColor(color);
	}

	for (size_t i = 0; i < totalLines.x; i++)
	{
		vlines[i].setSize(sf::Vector2f(lineThickness, verticalLineLength));
		vlines[i].setPosition(position + sf::Vector2f(i * (cellSize.x * scale.y + lineThickness) , 0));
		vlines[i].setFillColor(color);
	}
}

void Grid::load()
{

}

void Grid::update(float deltaTime)
{

}

void Grid::draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < totalLines.y; i++)
		window.draw(hlines[i]);

	for (size_t i = 0; i < totalLines.x; i++)
		window.draw(vlines[i]);
}
