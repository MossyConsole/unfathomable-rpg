#pragma once
#include <SFML/Graphics.hpp>

namespace GUI
{
	class Button
	{
	private:
		sf::Sprite sprite;
		sf::Texture texture;

		const sf::Vector2f& position;
		const sf::Vector2f& scale;
		sf::Vector2f* mouse_position;

		bool mouse_pressed;
		bool mouse_released;
		bool button_pressed;

	public:
		Button(const sf::Vector2f& position, const sf::Vector2f& scale);
		~Button();

		void initialize();
		void load();
		void update(double deltaTime, sf::Vector2f& mousePosition);
		void draw(sf::RenderWindow& window);

		bool isPressed();
	};
}

