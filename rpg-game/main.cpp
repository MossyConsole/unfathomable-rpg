#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "Player.h"
#include "Squid.h"

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

    Player player;
    Squid squid;
    player.initialize();
    squid.initialize();

    // -------------------------- INITIALIZE ----------------------------------


    // ----------------------------- LOAD -------------------------------------
  
    player.load();
    squid.load();

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

        player.update(squid);
        squid.update();

        // ---------------------------- UPDATE ------------------------------------


        // ----------------------------- DRAW -------------------------------------

        window.clear(Murky); // Clear the window and fill it solid

        player.draw(window);
        squid.draw(window);

        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------
    }
    return 0;
}