#include <iostream>
#include <SFML/Graphics.hpp>

// Custom colours
sf::Color Twilight = sf::Color::Color(0, 0, 0);
sf::Color Murky = sf::Color::Color(15, 28, 30);
sf::Color Deep = sf::Color::Color(48, 49, 96);
sf::Color Jelly = sf::Color::Color(139, 86, 120);
sf::Color Coral = sf::Color::Color(156, 118, 132);
sf::Color Foam = sf::Color::Color(170, 170, 170);
sf::Color Bubble = sf::Color::Color(255, 255, 255);

int main()
{
    // -------------------------- INITIALIZE ----------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Unfathomable", sf::Style::Default, settings); // RenderWindow class, window object, with arguments for the constructor (mode(x, y), name)

    // -------------------------- INITIALIZE ----------------------------------


    // ----------------------------- LOAD -------------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if (playerTexture.loadFromFile("assets/player/textures/scuba.png"))
    {
        playerSprite.setTexture(playerTexture);

        // x, y (used to select which image), width, height
        int tileWidth = 16;
        int tileHeight = 16;
        int xIndex = 0;
        int yIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(xIndex * tileWidth, yIndex * tileWidth, tileWidth, tileHeight)); // Set which texture to use
        playerSprite.setScale(sf::Vector2f(4, 4));
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
            playerSprite.setPosition(position + sf::Vector2f(0, -1));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));
        
        // ---------------------------- UPDATE ------------------------------------


        // ----------------------------- DRAW -------------------------------------

        window.clear(Murky); // Clear the window and fill it solid
        window.draw(playerSprite);
        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------

    }

    return 0;
}