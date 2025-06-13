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
#include "TilesheetDisplay.h"

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
    sf::Vector2f position = sf::Vector2f(90.0, 60.0);
    sf::Vector2i cellSize = sf::Vector2i(16, 16);
    sf::Vector2i totalCells = sf::Vector2i(18, 12);
    sf::Vector2i scale = sf::Vector2i(2, 2);
    int lineThickness = 1;
    sf::Color color = ui.Nope;

    Grid grid(position, cellSize, totalCells, scale, lineThickness, color);
    MouseTile mouseTile(grid);
    Map map(mouseTile, grid);
    Button button(sf::Vector2f(800, 300), sf::Vector2f(4, 4));
    MapSaver mapSaver;
    TilesheetDisplay tsDisplay;

    sf::Clock clock;
    float totalTime_ms = 0.0f;
    int frames = 0;

    sf::Mouse mouse;

    std::string fileName = "";
    bool buttonRaise = false;

    // FILE PATH
    // in main.cpp buttonIsPressed if statement
    // in mousetile.cpp load()
    // in tilesheetDisplay.cpp load()

    // -------------------------- INITIALIZE ----------------------------------

    grid.initialize();
    mouseTile.initialize();
    map.initialize();
    button.initialize();
    tsDisplay.initialize();

    // ----------------------------- LOAD -------------------------------------

    grid.load();
    tsDisplay.load();
    mouseTile.load(tsDisplay);
    map.load(mouseTile);
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
        map.update(deltaTime_ms, mousePosition, mouseTile);
        button.update(deltaTime_ms, mousePosition);
        tsDisplay.update(deltaTime_ms);

        // ----------------------------- DRAW -------------------------------------

        window.clear(ui.Twilight); // Clear the window and fill it solid
        
        grid.draw(window);
        tsDisplay.draw(window);
        map.draw(window);
        mouseTile.draw(window);
        button.draw(window);

        if (button.isPressed())
        {
            MapData mapData(
                "assets\\tilesheets\\overworld_tiles.png",
                fileName,
                grid.getTotalCells().x,
                grid.getTotalCells().y,
                grid.getCellSize().x,
                grid.getCellSize().y,
                grid.getScale().x,
                grid.getScale().y,
                grid.getTotalCells().x * grid.getTotalCells().y,
                map.getTileIDs());

            mapSaver.save(fileName, mapData);
            std::cout << "Map Saved" << std::endl;

            fileName = "";
        }

        window.display(); // Swap backbuffer with frontbuffer (screen)

        // ----------------------------- DRAW -------------------------------------

        // Handle File Naming
        if (buttonRaise)
        {
            buttonRaise = false;
            std::cout << "Name file: ";
            std::cin >> fileName;
            std::cout << fileName << " Started" << std::endl;
        }
        else if (fileName == "")
        {
            buttonRaise = true;
        }
    }
    return 0;
}