#include <vector>
#include "../inc/Boid.hpp"

// default dimensions for constructor
#define DEFAULT_X 1024
#define DEFAULT_Y 1024
#define DEFAULT_VEC_FACTOR (1.0/3.0)

/**
 * @brief represents the environment
 */
class Environment
{
public:
    // constructors
    Environment(double max_x, double max_y, double vec_1_factor, \
            double vec_2_factor, double vec_3_factor);
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

    /**
     * @brief computes the center of mass of all boids in the environment
     *
     * @returns the center of mass
     */
    Pos2D compute_center_of_mass();

    /**
     * @brief updates the position of all boids in the environment
     *
     * @param boids a vector of boids
     */
    void update_boid_positions();

    double max_x;
    double max_y;

private:
    // coefficients that determine how much the three vectors affect position
    double vec_1_factor;
    double vec_2_factor;
    double vec_3_factor;
    std::vector<Boid> boids;
};

