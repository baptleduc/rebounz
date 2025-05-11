#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "shape.hpp"



class Ball : public Shape
{   
    public:
        static constexpr float MASS = 100.0f; // Default mass of the ball
        static constexpr float RADIUS = 10.0f; // Default radius of the ball


        Ball(sf::Vector2f init_position, sf::Color color);

    void draw(sf:: RenderWindow& window);

    void update(float dt);
    bool isColliding(const Shape& shape);
    
    

    // Getters and Setters
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);

    private:
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::CircleShape shape;
        float mass;
        float radius;
        
        
};