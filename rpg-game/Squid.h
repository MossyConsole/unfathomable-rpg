#pragma once
#include <SFML/Graphics.hpp>
#include "Tools.h"

class Squid
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;

public:
	void initialize();
	void load();
	void update();
	void draw(sf::RenderWindow& window);
};

