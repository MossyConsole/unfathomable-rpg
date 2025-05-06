#include "Squid.h"
#include <iostream>

void Squid::initialize()
{
	
}
void Squid::load()
{
    if (texture.loadFromFile("assets/minor-enemies/textures/squid/squid.png"))
    {
        sprite.setTexture(texture);

        // x, y (used to select which image), width, height
        int tileWidth = 16;
        int tileHeight = 16;

        sprite.setScale(sf::Vector2f(4, 4));
        sprite.setPosition(50.0f, 25.0f);
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }
}
void Squid::update()
{

}
void Squid::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}