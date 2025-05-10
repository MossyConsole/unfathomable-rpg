#include "Bullet.h"
#include "Tools.h"
Bullet::Bullet() : 
	speed(0)
{
}
Bullet::~Bullet()
{
}

void Bullet::initialize(const sf::Vector2f& position, const sf::Vector2f& target, float speed)
{
	this->speed = speed;
	rectangleShape.setSize(sf::Vector2f(16.0f, 8.0f));
	rectangleShape.setPosition(position);
	direction = Tools::normalizeVector2f(target - position);
}
void Bullet::update(float deltaTime)
{
	rectangleShape.setPosition(rectangleShape.getPosition() + direction * speed * deltaTime);
}
void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(rectangleShape);
}

