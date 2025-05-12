#pragma once

#include <SFML/Graphics.hpp>

const sf::Vector2f GRAVITY_VECTOR(0.0f, 1700.0f); // Gravity vector in m/s^2
constexpr float FRICTION_COEFF = 0.05f;           // Coefficient of friction
constexpr float RESTITUTION_COEFF = 0.90f;        // Coefficient of restitution