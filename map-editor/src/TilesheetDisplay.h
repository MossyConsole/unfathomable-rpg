#pragma once
#include <SFML/Graphics.hpp>

class TilesheetDisplay
{
private:
	sf::Texture tilesheet;
	sf::Sprite sprite;

public:
	void initialize();
	void load();
	void update(double deltaTime);
	void draw(sf::RenderWindow& window);

	inline const sf::Vector2f getSpritePosition() { return sprite.getPosition(); }
};

