#include "Player.h"
#include <iostream>

void Player::initialize()
{
    size = sf::Vector2f(16, 16);
    speed = 0.8;
    
    bulletSpeed = 0.1f;

    boundingBox.setFillColor(sf::Color::Color(0, 0, 0, 0));
    boundingBox.setOutlineColor(sf::Color::Color(255, 0, 0, 64));
    boundingBox.setOutlineThickness(4);
}

void Player::load()
{
    if (texture.loadFromFile("assets/player/textures/scuba.png"))
    {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0 * size.x, 0 * size.y, size.x, size.y)); // Set which texture to use from the sprite sheet
        sprite.setPosition(500, 300);
        sprite.setScale(sf::Vector2f(4, 4));

        boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }
}

void Player::update(float deltaTime, Squid& squid)
{
    sf::Vector2f position = sprite.getPosition();

    // Single-line if statements
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.setPosition(position + sf::Vector2f(0.0f, -1.0f) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.setPosition(position + sf::Vector2f(-1.0f, 0.0f) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0.0f, 1.0f) * speed * deltaTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1.0f, 0.0f) * speed * deltaTime);


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
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }

    boundingBox.setPosition(sprite.getPosition());

    // Handle collisions
    if (Tools::checkRectCollision(sprite.getGlobalBounds(), squid.sprite.getGlobalBounds()))
    {
        boundingBox.setOutlineColor(sf::Color::Color(0, 255, 0, 128));
    }
    else if (boundingBox.getOutlineColor() != sf::Color::Color(255, 0, 0, 64))
    {
        boundingBox.setOutlineColor(sf::Color::Color(255, 0, 0, 64));
    }
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    for (size_t i = 0; i < bullets.size(); i++)
    {
        window.draw(bullets[i]);
    }

    window.draw(boundingBox);
}