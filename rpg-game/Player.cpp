#include "Player.h"
#include <iostream>

Player::Player() : speed(0.8f), maxFireRate(300.0f), fireRateTimer(0.0f)
{
}


void Player::initialize()
{
    size = sf::Vector2f(16, 16);

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

void Player::update(float deltaTime, Squid& squid, sf::Vector2f& mousePosition)
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

    // Bullet Code
    fireRateTimer += deltaTime;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= maxFireRate)
    {
        bullets.push_back(Bullet()); // Add a new element to the bullets vector
        int i = bullets.size() - 1;

        bullets[i].initialize(sprite.getPosition(), mousePosition, 0.4f);

        fireRateTimer = 0;
    }

    // Move the bullets
   

    for (size_t i = 0; i < bullets.size(); i++)
    {
        // Calculate direction every frame for heat-seeking
        // Calculate direction only once for accurate bullets
        bullets[i].update(deltaTime);

        if (squid.health > 0)
        {
            if (Tools::checkRectCollision(bullets[i].getGlobalBounds(), squid.sprite.getGlobalBounds()))
            {
                squid.changeHP(-5);
                bullets.erase(bullets.begin() + i); // Erase the bullet at the index 0 + i. Erase is a function that comes with a RectangleShape in SFML
            }
        }
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
        bullets[i].draw(window);

    window.draw(boundingBox);
}