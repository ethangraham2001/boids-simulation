#include <SFML/Graphics.hpp>
#include "../inc/Environment.hpp"

/**
 * MAIN function
 */
int main()
{
    Environment env;
    sf::RenderWindow window(sf::VideoMode(env.max_x, env.max_y), 
            "Boids Simulation");
}
