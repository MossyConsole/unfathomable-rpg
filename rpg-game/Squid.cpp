#include "Squid.h"
#include <iostream>

void Squid::initialize()
{
    size = sf::Vector2f(16, 16);
    speed = 0.04;

    boundingBox.setFillColor(sf::Color::Color(0, 0, 0, 0));
    boundingBox.setOutlineColor(sf::Color::Color(0, 0, 255, 64));
    boundingBox.setOutlineThickness(4);
}
void Squid::load()
{
    if (texture.loadFromFile("assets/minor-enemies/textures/squid/squid.png"))
    {
        sprite.setTexture(texture);
        sprite.setPosition(100.0f, 50.0f);
        sprite.setScale(sf::Vector2f(4, 4));

        boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }
}
void Squid::update(float deltaTime)
{
    boundingBox.setPosition(sprite.getPosition());
}
void Squid::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingBox);
}