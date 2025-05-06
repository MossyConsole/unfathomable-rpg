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

        sprite.setScale(sf::Vector2f(4, 4));
        sprite.setPosition(50.0f, 25.0f);
    }
    else
    {
        std::cout << "Enemy Image Failed to Load";
    }
}
void Squid::update()
{

}
void Squid::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}