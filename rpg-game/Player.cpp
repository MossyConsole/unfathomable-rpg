#include "Player.h"
#include <iostream>

void Player::initialize()
{
    bulletSpeed = 0.1f;
}

void Player::load()
{
    if (texture.loadFromFile("assets/player/textures/scuba.png"))
    {
        sprite.setTexture(texture);

        // x, y (used to select which image), width, height
        int tileWidth = 16;
        int tileHeight = 16;

        sprite.setTextureRect(sf::IntRect(0 * tileWidth, 0 * tileWidth, tileWidth, tileHeight)); // Set which texture to use
        sprite.setScale(sf::Vector2f(4, 4));
        sprite.setPosition(500, 300);
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }
}

void Player::update(Squid& squid)
{
    sf::Vector2f position = sprite.getPosition();

    // Single-line if statements
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0.0f, -0.1f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-0.1f, 0.0f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0.0f, 0.1f));

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(0.1f, 0.0f));


    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5))); // Add a new element to the bullets vector
        int i = bullets.size() - 1;
        bullets[i].setPosition(sprite.getPosition());
    }

    // Move the bullets
    for (size_t i = 0; i < bullets.size(); i++)
    {
        bulletDirection = squid.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Tools::normalizeVector2f(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }
}