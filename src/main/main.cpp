#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../inc/Environment.hpp"

#define BG_PATH "sky.jpg"

/**
 * MAIN function. Calls all computation and draws the boids
 */
int main()
{
    std::cout << "Intializing..." << std::endl;
    Environment env(800, 600, 1e-4, 1, 1);

    env.add_random_boids(100);

    sf::RenderWindow window(sf::VideoMode(env.max_x, env.max_y), 
            "Boids Simulation");

    sf:sf::Texture t;
    t.loadFromFile("sky.jpg");

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Black);
    circle.setPosition(300.f, 200.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        /* === UPDATE/DRAW BOIDS === */
        std::vector<Boid> boids = env.get_boids();
        for (auto b : boids)
        {
            // draw boids
            sf::CircleShape c(2.f);
            c.setFillColor(sf::Color::White);
            Pos2D b_pos = b.get_position();
            c.setPosition(b_pos.get_x(), b_pos.get_y());
            window.draw(c);

            // update boids
            env.update_boid_positions();
        }
        /* =========================*/


        window.display();
    }
}

