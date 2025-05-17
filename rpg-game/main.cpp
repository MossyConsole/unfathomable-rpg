#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "Player.h"
#include "Squid.h"
#include "UI.h"
#include "Map.h"
#include "MapLoader.h"

int main()
{
    // -------------------------- INITIALIZE ----------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // 960 x 640 (Alternative aspect ratio)
    sf::RenderWindow window(sf::VideoMode(1152, 768), "Unfathomable", sf::Style::Default, settings); // RenderWindow class, window object, with arguments for the constructor (mode(x, y), name)
    window.setFramerateLimit(60); // Set to the generally fastest monitor refresh rate

    sf::Clock clock;
    float totalTime_ms = 0.0f;
    int frames = 0;

    sf::Mouse mouse;

    Player player;
    Squid squid;
    UI ui(true);
    Map map;
    MapLoader mapLoader;

    player.initialize();
    squid.initialize();
    ui.initialize();
    map.initialize();
    mapLoader.load("level1.map");

    // -------------------------- INITIALIZE ----------------------------------


    // ----------------------------- LOAD -------------------------------------

    ui.load();
    player.load();
    squid.load();
    map.load();

    // ----------------------------- LOAD -------------------------------------

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
        ui.update(deltaTime_ms);
        map.update(deltaTime_ms);

        // ---------------------------- UPDATE ------------------------------------


        // ----------------------------- DRAW -------------------------------------

        window.clear(ui.Nope); // Clear the window and fill it solid

        // Map
        map.draw(window); 

        // Entities
        player.draw(window);
        squid.draw(window);

        // UI
        ui.draw(window);

        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------
    }
    return 0;
}