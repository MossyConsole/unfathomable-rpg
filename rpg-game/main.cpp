#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "Player.h"
#include "Squid.h"
#include "UI.h"

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
    window.setFramerateLimit(60); // Set to the generally fastest monitor refresh rate

    sf::Clock clock;
    float totalTime_ms = 0.0f;
    int frames = 0;

    sf::Mouse mouse;

    Player player;
    Squid squid;
    UI ui(true);

    player.initialize();
    squid.initialize();
    ui.initialize();

    // -------------------------- INITIALIZE ----------------------------------


    // ----------------------------- LOAD -------------------------------------

    ui.load();
    player.load();
    squid.load();

    // ----------------------------- LOAD -------------------------------------

    // Keep window open with a while loop
    // main game loop
    while (window.isOpen())
    {
        // ---------------------------- UPDATE ------------------------------------
        // Fix deltaTime
        sf::Time deltaTime = clock.restart(); // Get time since last restart, then restart it
        float deltaTime_ms = deltaTime.asMilliseconds();
        totalTime_ms += deltaTime_ms;
        frames++;

        if (totalTime_ms >= 1000)
        {
            std::string frameRateString = "FPS: " + std::to_string(frames);
            ui.setFrameRateText(frameRateString);

            totalTime_ms = 0.0f;
            frames = 0;
        }
       
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

        sf::Vector2f mousePosition = sf::Vector2f(mouse.getPosition(window));
        player.update(deltaTime_ms, squid, mousePosition);
        squid.update(deltaTime_ms);

        // ---------------------------- UPDATE ------------------------------------


        // ----------------------------- DRAW -------------------------------------

        window.clear(Murky); // Clear the window and fill it solid

        player.draw(window);
        squid.draw(window);
        ui.draw(window);

        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------
    }
    return 0;
}