#include "Button.h"
#include <iostream>

GUI::Button::Button(const sf::Vector2f& position, const sf::Vector2f& scale) :
	position(position), scale(scale), mouse_position(nullptr), 
	mouse_pressed(false), mouse_released(false), button_pressed(false)
{
}

GUI::Button::~Button()
{
}

void GUI::Button::initialize()
{
}

void GUI::Button::load()
{
	texture.loadFromFile("../rpg-game/assets/gui/button.png");
	sprite = sf::Sprite(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite.setPosition(position);
	sprite.setScale(scale);
}

void GUI::Button::update(double deltaTime, sf::Vector2f& mousePosition)
{
	mouse_position = &mousePosition;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		mouse_pressed = true;
	}
	else
	{
		mouse_pressed = false;
		mouse_released = true;
	}

}

bool GUI::Button::isPressed()
{
	if (mouse_pressed)
	{
		sf::Vector2f pos = sprite.getPosition();

		// Check for mouse-button interaction
		if ((pos.x < mouse_position->x && (pos.x + sprite.getGlobalBounds().width) > mouse_position->x)
			&& (pos.y < mouse_position->y && (pos.y + sprite.getGlobalBounds().height) > mouse_position->y))
		{
			button_pressed = true;
			sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
		}
	}
	else if (mouse_released && button_pressed)
	{
		mouse_released = false;
		button_pressed = false;

		if (sprite.getTextureRect() != sf::IntRect(0, 0, 16, 16))
		{
			sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
		}

		return true;
	}
	return false;
}

void GUI::Button::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
