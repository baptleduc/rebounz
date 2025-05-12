#include <SFML/Graphics.hpp>

#include "utils.hpp"
#include <cmath>

float get_euclidean_distance_squared(const sf::Vector2f &a,
                                     const sf::Vector2f &b) {
    sf::Vector2f diff = a - b;
    return diff.x * diff.x + diff.y * diff.y;
}

float get_vector_length_squared(const sf::Vector2f &vector) {
    return vector.x * vector.x + vector.y * vector.y;
}

float get_vector_length(const sf::Vector2f &vector) {
    return std::sqrt(get_vector_length_squared(vector));
}