#include <vector>
#include "../inc/Boid.hpp"

/**
 * @brief represents the environment
 */
class Environment
{
public:
    // constructors
    Environment(double max_x, double max_y);
    Environment();

    /**
     * @brief adds a single Boid to the envionment
     *
     * @param boid a Boid
     */
    void add_boid(Boid boid);

    /**
     * @brief adds a vector of Boids to the envionment
     *
     * @param boid a vector of Boids
     */
    void add_boids(std::vector<Boid> boids);

private:
    double max_x;
    double max_y;
    std::vector<Boid> Boids;
};

