/**
 * Author: Ethan Graham
 */

#include "Pos2D.hpp"
#include "Velocity2D.hpp"
#include <vector>

/**
 * @brief represents a bird-oid object (boid)
 */
class Boid
{
public:
    /**
     * @brief constructor for Boid
     *
     * @param init_x initial x-axis position
     * @param init_y initial y_axis position
     * @param rule2_dist distance parameter for rule2 computation
     */
    Boid(Pos2D position, Vec2D velocity, double range_avoid, \
            double range_align, double max_speed);

    /**
     * @brief boids rule 1: flock towards center of mass
     */
    Vec2D compute_vec_rule1(Pos2D center_of_mass);

    /**
     * @brief boids rule 2: avoid boids that are close
     */
    Vec2D compute_vec_rule2(std::vector<Boid> boids);

    /**
     * @brief boids rule 3: align speed with boids
     */
    Vec2D compute_vec_rule3(std::vector<Boid> boids);

    /**
     * getters and setters
     */
    Pos2D get_position();
    Vec2D get_velocity();

    Pos2D set_position();
    Pos2D set_velocity();

private:
    Pos2D position;         // position of a boid
    Vec2D velocity;    // velocity of a boid
    double range_avoid;     // will avoid other boids in this range
    double range_align;     // will align with other boids in this range
    double max_speed;       // max speed of the boid
};

