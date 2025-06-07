#pragma once
#include <SFML/Graphics.hpp>

class UI
{
public:
	// Custom Colours
	sf::Color Twilight = sf::Color::Color(0, 0, 0);
	sf::Color Murky = sf::Color::Color(15, 28, 30);
	sf::Color Deep = sf::Color::Color(48, 49, 96);
	sf::Color Jelly = sf::Color::Color(139, 86, 120);
	sf::Color Coral = sf::Color::Color(156, 118, 132);
	sf::Color Foam = sf::Color::Color(170, 170, 170);
	sf::Color Bubble = sf::Color::Color(255, 255, 255);
	sf::Color Nope = sf::Color::Color(173, 27, 95);

private:
	sf::Text frameRateText; // Sprite
	sf::Font font; // Texture
	bool showFramesPerSecond;
public:
	UI(bool showFPS);
	~UI();

	void initialize();
	void load();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void setFrameRateText(std::string frameRateString);
};

