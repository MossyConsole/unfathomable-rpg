#include "Tools.h"

sf::Vector2f Tools::normalizeVector2f(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    vector.x /= magnitude;
    vector.y /= magnitude;

    return sf::Vector2f(vector.x, vector.y);
}

bool Tools::checkRectCollision(sf::FloatRect rect_A, sf::FloatRect rect_B)
{
    // Get bounds of rect_A
    float rect_A_left = rect_A.left;
    float rect_A_top = rect_A.top;
    float rect_A_right = rect_A.left + rect_A.width - 1.0f; // -1 because the pixel of position.x is also counted in getSize()
    float rect_A_bottom = rect_A.top + rect_A.height - 1.0f;

    // Get bounds of rect_B
    float rect_B_left = rect_B.left;
    float rect_B_top = rect_B.top;
    float rect_B_right = rect_B.left + rect_B.width - 1.0f; // -1 because the pixel of position.x is also counted in getSize()
    float rect_B_bottom = rect_B.top + rect_B.height - 1.0f;

    // Check for collision on x axis
    if ((rect_A_left <= rect_B_right) && (rect_A_right > rect_B_left))
    {
        // Check for collision on y axis
        if ((rect_A_bottom >= rect_B_top) && (rect_A_top < rect_B_bottom))
        {
            return true;
        }
    }

    return false;
}
