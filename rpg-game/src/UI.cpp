#include "UI.h"
#include <iostream>

UI::UI(bool showFPS = false)
{
	showFramesPerSecond = showFPS;
}
UI::~UI()
{
}

void UI::initialize()
{
	frameRateText.setCharacterSize(18);
	frameRateText.setPosition(sf::Vector2f(4, 0));
}
void UI::load()
{
    if (font.loadFromFile("assets/fonts/gameboy.ttf"))
    {
        frameRateText.setFont(font);
    }
    else
    {
        std::cout << "Font not loaded." << std::endl;
    }
}
void UI::update(float deltaTime) {}
void UI::draw(sf::RenderWindow& window)
{
    if (showFramesPerSecond)
        window.draw(frameRateText);
}
void UI::setFrameRateText(std::string frameRateString)
{
    frameRateText.setString(frameRateString);
}
