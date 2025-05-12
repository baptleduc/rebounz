#pragma once

#include <SFML/Graphics.hpp>
/**
 * @brief Returns the euclidean get_euclidean_distance_squared between two
 * points.
 */
float get_euclidean_distance_squared(const sf::Vector2f &a,
                                     const sf::Vector2f &b);

/**
 * @brief Returns the squared length of a vector.
 */
float get_vector_length_squared(const sf::Vector2f &vector);

float get_vector_length(const sf::Vector2f &vector);