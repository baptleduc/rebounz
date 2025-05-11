#include "ball.hpp"
#include "constants.hpp"
#include <iostream>


Ball::Ball(sf::Vector2f init_position, sf::Color color)
    : position(init_position), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), radius(RADIUS), mass(MASS)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}
void Ball::update(float dt)
{
    // Update the position based on velocity and acceleration
    acceleration = GRAVITY_VECTOR - (FRICTION_COEFF/mass) * velocity;
    velocity += acceleration * dt;
    position += velocity * dt;

    // Update the shape's position
    shape.setPosition(position);
}