#include "ball.hpp"
#include "constants.hpp"
#include "utils.hpp"
#include <iostream>

Ball::Ball(sf::Vector2f init_position, sf::Color color,
           sf::CircleShape main_circle)
    : position(init_position), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f),
      radius(RADIUS), mass(MASS), main_circle(main_circle), is_falling(true) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow &window) { window.draw(shape); }

bool Ball::is_collision_with_main_circle(sf::Vector2f next_position) {
    // Check for collision with the main circle
    sf::Vector2f main_circle_center =
        main_circle.getPosition() +
        sf::Vector2f(main_circle.getRadius(), main_circle.getRadius());
    sf::Vector2f ball_center = position + sf::Vector2f(radius, radius);
    float distance_squared =
        get_euclidean_distance_squared(main_circle_center, ball_center);
    float radius_sum =
        main_circle.getRadius() - main_circle.getOutlineThickness() - radius;
    return distance_squared >= (radius_sum * radius_sum);
}

void Ball::update(float dt) {
    if (!is_falling)
        return;

    // Update the position based on velocity and acceleration
    sf::Vector2f next_acceleration =
        GRAVITY_VECTOR - (FRICTION_COEFF / mass) * velocity;
    sf::Vector2f next_velocity = velocity + next_acceleration * dt;
    sf::Vector2f next_position = position + next_velocity * dt;

    // Check if the next position is colliding with the main circle
    bool is_collision = is_collision_with_main_circle(next_position);

    if (is_collision && get_vector_length_squared(velocity) <
                            VELOCITY_THRESHOLD * VELOCITY_THRESHOLD) {
        // Update velocity and acceleration of the Ball object
        is_falling = false;
        velocity = sf::Vector2f(0.0f, 0.0f);
        acceleration = sf::Vector2f(0.0f, 0.0f);

    } else if (is_collision) {
        // Rebound
        velocity = -velocity * RESTITUTION_COEFF;
        position += velocity * dt;

    } else {
        acceleration = next_acceleration;
        velocity = next_velocity;
        position = next_position;
    }

    // Commit position to the shape
    shape.setPosition(position);
}