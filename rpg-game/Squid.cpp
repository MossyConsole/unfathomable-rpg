#include "Squid.h"
#include <iostream>

void Squid::initialize()
{
    size = sf::Vector2f(16, 16);
    speed = 0.04;

    boundingBox.setFillColor(sf::Color::Color(0, 0, 0, 0));
    boundingBox.setOutlineColor(sf::Color::Color(0, 0, 255, 64));
    boundingBox.setOutlineThickness(4);

    healthText.setCharacterSize(12);
    healthText.setFillColor(sf::Color::Color(200, 0, 0));
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
        std::cout << "Squid Image Failed to Load";
    }

    if (font.loadFromFile("assets/fonts/gameboy.ttf"))
    {
        healthText.setFont(font);
        healthText.setString(std::to_string(health));
    }
    else
    {
        std::cout << "Font not loaded." << std::endl;
    }
}
void Squid::update(float deltaTime)
{
    if (health > 0)
    {
        boundingBox.setPosition(sprite.getPosition());
        healthText.setPosition(sprite.getPosition());
    }
}
void Squid::draw(sf::RenderWindow& window)
{
    if (health > 0)
    {
        window.draw(sprite);
        window.draw(healthText);
        window.draw(boundingBox);
    }
}
void Squid::changeHP(float difference = 0)
{
    health += difference;
    healthText.setString(std::to_string(health));
}