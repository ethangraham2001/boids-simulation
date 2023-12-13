#include "../inc/Environment.hpp"
#include <iterator>

Environment::Environment(double max_x, double max_y, double vec_1_factor, \
        double vec_2_factor, double vec_3_factor)
{
    this->max_x = max_x;
    this->max_y = max_x;
    this->vec_1_factor = vec_1_factor;
    this->vec_2_factor = vec_2_factor;
    this->vec_3_factor = vec_3_factor;
}

Environment::Environment()
{
    Environment(DEFAULT_X, DEFAULT_Y, DEFAULT_VEC_FACTOR, DEFAULT_VEC_FACTOR, \
            DEFAULT_VEC_FACTOR);
}

void Environment::add_boid(Boid boid)
{
    this->boids.push_back(boid);
}

void Environment::add_boids(std::vector<Boid> boids)
{
    this->boids.insert(std::end(this->boids), 
            std::begin(boids), std::end(boids));
}

Pos2D Environment::compute_center_of_mass()
{
    Pos2D center_of_mass(0, 0);
    for (Boid boid : this->boids)
        center_of_mass += (boid.get_position());

    return center_of_mass;
}

void Environment::update_boid_positions()
{
    auto center_of_mass = compute_center_of_mass();

    // compute velocities
    for (auto& boid : this->boids)
    {
        Vec2D vec1 = boid.compute_vec_rule1(center_of_mass);
        Vec2D vec2 = boid.compute_vec_rule2(this->boids);
        Vec2D vec3 = boid.compute_vec_rule3(this->boids);

        vec1 *= vec_1_factor;
        vec2 *= vec_2_factor;
        vec3 *= vec_3_factor;

        Vec2D final_vec = vec1 + vec2 + vec3;
        boid.set_velocity(final_vec);
    }

    // compute new positions
    for (auto& boid : this->boids)
    {
        Pos2D new_pos = boid.get_position() + boid.get_velocity();
        boid.set_position(new_pos);
    }
}

