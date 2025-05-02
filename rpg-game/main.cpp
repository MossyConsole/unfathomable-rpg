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
    // INITIALIZE

    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Unfathomable", sf::Style::Default, settings); // RenderWindow class, window object, with arguments for the constructor (mode(x, y), name)


    // Keep window open with a while loop
    // main game loop
    while(window.isOpen())
    {
        // UPDATE
        
        // Event loop for the window
        // Save current event polled in a variable called event
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }


        // DRAW

        window.clear(Murky); // Clear the window and fill it solid

        window.display(); // Swap backbuffer with frontbuffer (screen)
    }

    return 0;
}