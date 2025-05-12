#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "simulation.hpp"
#include "ball.hpp"




Simulation::Simulation(int window_width, int window_height, int ball_count)
    :window(sf::VideoMode(window_width, window_height), "Ball Simulation"),
     main_circle( window_width < window_height ? window_width / 3.0 : window_height / 3.0) // min(window_width, window_height) / 3.0)
{   
    // Initialize the window
    window.setFramerateLimit(60); // Set the frame rate limit


    

    // Intialize main circle
    main_circle.setFillColor(sf::Color::Red);
    main_circle.setPosition(window_width / 2.0 - main_circle.getRadius(), window_height / 2.0 - main_circle.getRadius());
    main_circle.setOutlineColor(sf::Color::Red);
    main_circle.setOutlineThickness(5.f); 
    main_circle.setFillColor(sf::Color::Transparent);  // Pas de remplissage

    // Initialize balls
    balls.reserve(ball_count);
    sf::Vector2f init_pos(window_width / 2.0, window_height / 3.0);
    for (int i = 0; i < ball_count; ++i)
    {
        Ball ball(init_pos, sf::Color::White, main_circle);
        balls.push_back(ball);
    }
}

void Simulation::run()
{
    sf::Clock clock;
    window.draw(main_circle);

    
    int idx= 0;
    bool isFalling = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed)
            {   
                isFalling = true;
            }
            
        }

        // Update the simulation
        float dt = clock.restart().asSeconds();
        for (auto& ball : balls)
        {
            if (isFalling) ball.update(dt);
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the drawable objects
        for (auto& ball : balls)
        {   
            window.draw(main_circle);
            ball.draw(window);
        }

        // Display the contents of the window
        window.display();

    }
}


