#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player() : speed(0.4f), maxFireRate(300.0f), fireRateTimer(0.0f)
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
        sprite.setPosition(600, 350);
        sprite.setScale(sf::Vector2f(4, 4));

        boundingBox.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }
}

void Player::update(float deltaTime, Squid& squid, Map& map, sf::Vector2f& mousePosition)
{
    int tileC = map.getMapTileCount();
    int keysPressed = 0;

    const sf::Vector2f position = sprite.getPosition();
    sf::Vector2f newPos = position;

    // Handle movement and map collisions
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        newPos += sf::Vector2f(0.0f, -1.0f) * speed * deltaTime;
        moving = true;
        keysPressed++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        newPos += sf::Vector2f(-1.0f, 0.0f) * speed * deltaTime;
        moving = true;
        keysPressed++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        newPos += sf::Vector2f(0.0f, 1.0f) * speed * deltaTime;
        moving = true;
        keysPressed++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        newPos += sf::Vector2f(1.0f, 0.0f) * speed * deltaTime;
        moving = true;
        keysPressed++;
    }

    if (keysPressed == 2)
    {
        float diagonalSpeed = 1 / std::sqrt(2);
        // Diagonal movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            newPos = position + (sf::Vector2f(-diagonalSpeed, -diagonalSpeed) * speed * deltaTime);
            moving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            newPos = position + (sf::Vector2f(diagonalSpeed, -diagonalSpeed) * speed * deltaTime);
            moving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            newPos = position + (sf::Vector2f(-diagonalSpeed, diagonalSpeed) * speed * deltaTime);
            moving = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            newPos = position + (sf::Vector2f(diagonalSpeed, diagonalSpeed) * speed * deltaTime);
            moving = true;
        }
    }

    Map::customSprite collisionSprites[2];

    // Find which tile the player will land on
    for (size_t i = 0; i < tileC; i++)
    {
        sf::FloatRect playerSpriteBounds = sprite.getGlobalBounds();

        sf::FloatRect newPlayerSpriteX = sf::FloatRect(newPos.x, playerSpriteBounds.top,
            playerSpriteBounds.width, playerSpriteBounds.height);

        sf::FloatRect newPlayerSpriteY = sf::FloatRect(playerSpriteBounds.left, newPos.y,
            playerSpriteBounds.width, playerSpriteBounds.height);


        if (Tools::checkRectCollision(newPlayerSpriteX, map.getMapSprites()[i].sprite.getGlobalBounds()))
        {
            if (map.getMapSprites()[i].hasCollision)
            {
                isCollidingX = true;
                // std::cout << "Collision X" << std::endl;
                newPos.x = position.x;
                collisionSprites[0] = map.getMapSprites()[i];
            }
        }

        if (Tools::checkRectCollision(newPlayerSpriteY, map.getMapSprites()[i].sprite.getGlobalBounds()))
        {
            if (map.getMapSprites()[i].hasCollision)
            {
                isCollidingY = true;
                // std::cout << "Collision Y" << std::endl;
                newPos.y = position.y;
                collisionSprites[1] = map.getMapSprites()[i];
            }
        }
    }

    // Move the player if they don't collide. If they would collide, smoothly move the player pixel by pixel until they do
    if (moving)
    {
        sprite.setPosition(newPos);
        moving = false;
    }

    if (isCollidingX)
    {
        isCollidingX = false;

        // Pixel-perfect collisions
        int tileLeft = collisionSprites[0].sprite.getGlobalBounds().left;
        int tileRight = collisionSprites[0].sprite.getGlobalBounds().left + collisionSprites[0].sprite.getGlobalBounds().width - 1;
        int playerLeft = sprite.getGlobalBounds().left; 
        int playerRight = sprite.getGlobalBounds().left + sprite.getGlobalBounds().width - 1;

        if (tileRight + 1 < playerLeft)
        {
            sprite.setPosition(position + sf::Vector2f(-1.0f, 0.0f));
        }
        else if (tileLeft - 1 > playerRight)
        {
            sprite.setPosition(position + sf::Vector2f(1.0f, 0.0f));
        }
    }
    if (isCollidingY)
    {
        isCollidingY = false;

        // Pixel-perfect collisions
        int tileTop = collisionSprites[1].sprite.getGlobalBounds().top;
        int tileBottom = collisionSprites[1].sprite.getGlobalBounds().top + collisionSprites[1].sprite.getGlobalBounds().height - 1;
        int playerTop = sprite.getGlobalBounds().top;
        int playerBottom = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height - 1;

        if (tileBottom + 1 < playerTop)
        {
            sprite.setPosition(sprite.getPosition() + sf::Vector2f(0.0f, -1.0f));
        }
        else if (tileTop - 1 > playerBottom)
        {
            sprite.setPosition(sprite.getPosition() + sf::Vector2f(0.0f, 1.0f));
        }
    }

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

    // Handle entity collisions
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