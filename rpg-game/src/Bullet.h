#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::RectangleShape rectangleShape;
	sf::Vector2f direction;
	float speed;

public:
	Bullet();
	~Bullet();

	void initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed);
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	// Inline tells the compiler to copy and paste the function's code into the place where it is called, instead of making a function call
	// This can save performance for small functions of one-two lines
	inline const sf::FloatRect& getGlobalBounds() { return rectangleShape.getGlobalBounds(); }
};

