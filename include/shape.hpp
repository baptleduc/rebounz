#pragma once

#include <SFML/Graphics.hpp>

class Shape {
    public:
        virtual ~Shape() = default;
        virtual void draw(sf::RenderWindow &window) = 0;
};
