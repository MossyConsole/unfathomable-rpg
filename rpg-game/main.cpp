#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

// Custom colours
sf::Color Twilight = sf::Color::Color(0, 0, 0);
sf::Color Murky = sf::Color::Color(15, 28, 30);
sf::Color Deep = sf::Color::Color(48, 49, 96);
sf::Color Jelly = sf::Color::Color(139, 86, 120);
sf::Color Coral = sf::Color::Color(156, 118, 132);
sf::Color Foam = sf::Color::Color(170, 170, 170);
sf::Color Bubble = sf::Color::Color(255, 255, 255);

// Custom Functions
sf::Vector2f normalizeVector2f(sf::Vector2f vector);

int main()
{
    // -------------------------- INITIALIZE ----------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Unfathomable", sf::Style::Default, settings); // RenderWindow class, window object, with arguments for the constructor (mode(x, y), name)

    // -------------------------- INITIALIZE ----------------------------------

    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0.1f;

    // ----------------------------- LOAD -------------------------------------
    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Sprite playerSprite;
    sf::Sprite enemySprite;

    if (playerTexture.loadFromFile("assets/player/textures/scuba.png"))
    {
        playerSprite.setTexture(playerTexture);

        // x, y (used to select which image), width, height
        int tileWidth = 16;
        int tileHeight = 16;

        playerSprite.setTextureRect(sf::IntRect(0 * tileWidth, 0 * tileWidth, tileWidth, tileHeight)); // Set which texture to use
        playerSprite.setScale(sf::Vector2f(4, 4));
        playerSprite.setPosition(500, 300);
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }
    if (enemyTexture.loadFromFile("assets/minor-enemies/textures/squid/squid.png"))
    {
        enemySprite.setTexture(enemyTexture);

        // x, y (used to select which image), width, height
        int tileWidth = 16;
        int tileHeight = 16;

        enemySprite.setScale(sf::Vector2f(4, 4));
        enemySprite.setPosition(50.0f, 25.0f);
    }
    else
    {
        std::cout << "Player Image Failed to Load";
    }

    // ----------------------------- LOAD -------------------------------------

    // Keep window open with a while loop
    // main game loop
    while (window.isOpen())
    {
        // ---------------------------- UPDATE ------------------------------------

        // Event loop for the window
        // Save current event polled in a variable called event
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        sf::Vector2f position = playerSprite.getPosition();

        // Single-line if statements
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            playerSprite.setPosition(position + sf::Vector2f(0.0f, -0.1f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-0.1f, 0.0f));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0.0f, 0.1f));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(0.1f, 0.0f));
        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(10, 5))); // Add a new element to the bullets vector
            int i = bullets.size() - 1;
            bullets[i].setPosition(playerSprite.getPosition()); 
        }

        // Move the bullets
        for (size_t i = 0; i < bullets.size(); i++)
        {
            bulletDirection = enemySprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normalizeVector2f(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }

        // ---------------------------- UPDATE ------------------------------------


        // ----------------------------- DRAW -------------------------------------

        window.clear(Murky); // Clear the window and fill it solid
        window.draw(enemySprite);
        window.draw(playerSprite);
        for (size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------

    }

    return 0;
}


sf::Vector2f normalizeVector2f(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    vector.x /= magnitude;
    vector.y /= magnitude;

    return sf::Vector2f(vector.x, vector.y);
}