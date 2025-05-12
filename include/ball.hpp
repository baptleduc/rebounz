#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>




class Ball
{   
    public:
        static constexpr float MASS = 100.0f; // Default mass of the ball
        static constexpr float RADIUS = 10.0f; // Default radius of the ball
        static constexpr float VELOCITY_THRESHOLD = 70.0f; // Threshold for velocity to consider it as "moving"


        Ball(sf::Vector2f init_position, sf::Color color, sf::CircleShape main_circle);

    void draw(sf:: RenderWindow& window);

    void update(float dt);
    
    

    // Getters and Setters
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& position);

    private:
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::CircleShape shape;
        sf::CircleShape main_circle;
        float mass;
        float radius;
        bool is_falling;

        bool is_collision_with_main_circle(sf::Vector2f next_position);
        
        
};