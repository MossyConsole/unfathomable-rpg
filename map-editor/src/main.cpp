#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <core/MapData.h>

#include "../../rpg-game/src/UI.cpp"
#include "../../rpg-game/src/UI.h"
#include "Grid.h"
#include "MouseTile.h"
#include "Map.h"
#include "GUI/Button.h"
#include "MapSaver.h"

using namespace GUI;
int main()
{
    // -------------------------- INITIALIZE ----------------------------------

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    // 960 x 640 (Alternative aspect ratio)
    sf::RenderWindow window(sf::VideoMode(1152, 768), "Unfathomable - Map Editor", sf::Style::Default, settings); // RenderWindow class, window object, with arguments for the constructor (mode(x, y), name)
    window.setFramerateLimit(60); // Set to the generally fastest monitor refresh rate

    UI ui(false);

    // Position and number of rows & columns
    sf::Vector2f position = sf::Vector2f(30.0, 20.0);
    sf::Vector2i cellSize = sf::Vector2i(16, 16);
    sf::Vector2i totalCells = sf::Vector2i(24, 16);
    sf::Vector2i scale = sf::Vector2i(2, 2);
    int lineThickness = 2;
    sf::Color color = ui.Nope;


    Grid grid(position, cellSize, totalCells, scale, lineThickness, color);
    MouseTile mouseTile(grid);
    Map map(mouseTile, grid);
    Button button(sf::Vector2f(900, 300), sf::Vector2f(4, 4));
    MapSaver mapSaver;

    MapData mapData;

    mapData.tilesheet = "assets\\tilesheets\\overworld_tiles.png";
    mapData.name = "Level 2";
    mapData.tileWidth = 16;
    mapData.tileHeight = 16;
    mapData.scaleX = 4;
    mapData.scaleY = 4;
    mapData.dataLength = 25;
    // mapData.data = new int[mapData.dataLength];
    // mapData.data = {10, 10, 10, 10, 10, 10, 0, 1, 2, 10, 10, 6, 7, 8, 10, 10, 6, 7, 8, 10, 10, 12, 13, 14, 10};

    sf::Clock clock;
    float totalTime_ms = 0.0f;
    int frames = 0;

    sf::Mouse mouse;

    mapSaver.save("level2", mapData);

    // -------------------------- INITIALIZE ----------------------------------

    grid.initialize();
    mouseTile.initialize();
    map.initialize();
    button.initialize();

    // ----------------------------- LOAD -------------------------------------

    grid.load();
    mouseTile.load();
    map.load();
    button.load();

    // ----------------------------- LOAD -------------------------------------

    // main game loop
    while (window.isOpen())
    {
        // ---------------------------- UPDATE ------------------------------------
        // Fix window size
        window.setSize(sf::Vector2u(1152, 768));

        // DeltaTime
        sf::Time deltaTime = clock.restart(); // Get time since last restart, then restart it
        float deltaTime_ms = deltaTime.asMilliseconds();
        totalTime_ms += deltaTime_ms;
        frames++;

        if (totalTime_ms >= 1000)
        {
            std::string frameRateString = "FPS: " + std::to_string(frames);;

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

        // ---------------------------- UPDATE ------------------------------------

        grid.update(deltaTime_ms);
        mouseTile.update(deltaTime_ms, mousePosition);
        map.update(deltaTime_ms, mousePosition);
        button.update(deltaTime_ms, mousePosition);

        // ----------------------------- DRAW -------------------------------------

        window.clear(ui.Twilight); // Clear the window and fill it solid
        
        grid.draw(window);
        mouseTile.draw(window);
        map.draw(window);
        button.draw(window);

        if (button.isPressed())
        {
            std::cout << "Button Pressed" << std::endl;
        }

        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------
    }
    return 0;
}