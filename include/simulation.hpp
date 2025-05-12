#pragma once

#include <SFML/Window.hpp>

#include "ball.hpp"

class Simulation {
    public:
        Simulation(int window_width, int window_height, int ball_count);

        void run();

    private:
        sf::RenderWindow window;
        sf::CircleShape main_circle;
        std::vector<Ball> balls;
};