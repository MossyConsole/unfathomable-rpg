#include "Tools.h"

sf::Vector2f Tools::normalizeVector2f(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    vector.x /= magnitude;
    vector.y /= magnitude;

    return sf::Vector2f(vector.x, vector.y);
}