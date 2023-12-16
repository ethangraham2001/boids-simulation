/**
 * Author: Ethan Graham
 */

#include "Pos2D.hpp"
#include "Vec2D.hpp"
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
    Boid(Pos2D init_pos, Vec2D init_vel, \
            double range_align, double range_avoid, double max_velocity);

    /**
     * @brief computes distance between this boid and another
     *
     * @param other another Boid
     */
    double distance_to(const Boid& other) const;

    /**
     * @brief computes the perceived center of mass of a boid
     */
    Pos2D perceived_center_of_mass(std::vector<Boid>& boids);

    /**
     * @brief boids rule 1: flock towards center of mass
     */
    Vec2D compute_vec_rule1(const Pos2D& center_of_mass);

    /**
     * @brief boids rule 2: avoid boids that are close
     */
    Vec2D compute_vec_rule2(const std::vector<Boid>& boids);

    /**
     * @brief boids rule 3: align speed with boids
     */
    Vec2D compute_vec_rule3(const std::vector<Boid>& boids);

    /**
     * getters and setters
     */
    Pos2D get_position() const;
    Vec2D get_velocity() const;
    double get_max_velocity() const;

    Pos2D set_position(const Pos2D new_position);
    Vec2D set_velocity(const Vec2D new_velocity);


private:
    Pos2D position;         // position of a boid
    Pos2D next_position;    // next position of a boid
    Vec2D velocity;         // velocity of a boid
    double range_avoid;     // will avoid other boids in this range
    double range_align;     // will align with other boids in this range
    double max_velocity;       // max speed of the boid
};

