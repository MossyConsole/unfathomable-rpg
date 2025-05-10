#pragma once
#include <SFML/Graphics.hpp>

class UI
{
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

