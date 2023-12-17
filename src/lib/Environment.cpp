#include "../inc/Environment.hpp"
#include <iterator>
#include <ostream>
#include <random>
#include <thread>

// uncomment for multihreaded implementation
// #define MULTITHREADED

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

    center_of_mass *= (1.0/boids.size());
    return center_of_mass;
}

void Environment::update_boid_positions()
{
    auto center_of_mass = compute_center_of_mass();
    // compute velocities

    /* velocity computation done multithreaded */

#ifdef MULTITHREADED
    std::vector<std::thread> threads;
    for (auto& boid : this->boids)
    {

        threads.emplace_back([center_of_mass, this, &boid] {
            Vec2D vec1 = boid.compute_vec_rule1(center_of_mass);
            Vec2D vec2 = boid.compute_vec_rule2(this->boids);
            Vec2D vec3 = boid.compute_vec_rule3(this->boids);

            vec1 *= vec_1_factor;
            vec2 *= vec_2_factor;
            vec3 *= vec_3_factor;

            Vec2D final_vec = vec1 + vec2 + vec3;

            if (final_vec.norm() > boid.get_max_velocity())
                final_vec *= (boid.get_max_velocity() / final_vec.norm());

            boid.set_velocity(final_vec);
        });
    }
    for (auto& thread : threads)
        thread.join();
#endif
#ifndef MULTITHREADED
    for (auto& boid : this->boids)
    {

        Vec2D vec1 = boid.compute_vec_rule1(center_of_mass);
        Vec2D vec2 = boid.compute_vec_rule2(this->boids);
        Vec2D vec3 = boid.compute_vec_rule3(this->boids);

        vec1 *= vec_1_factor;
        vec2 *= vec_2_factor;
        vec3 *= vec_3_factor;

        Vec2D final_vec = vec1 + vec2 + vec3;

        if (final_vec.norm() > boid.get_max_velocity())
            final_vec *= (boid.get_max_velocity() / final_vec.norm());

        boid.set_velocity(final_vec);
    }
#endif

    // compute new positions
    for (auto& boid : this->boids)
    {
        Vec2D new_velocity = boid.get_velocity();
        Pos2D new_pos = boid.get_position() + boid.get_velocity();
        boid.set_position(new_pos);

        if (is_out_of_bounds(boid))
        {
            auto vel = boid.get_velocity();
            vel *= -0.5;
            boid.set_velocity(vel);
        }
    }
}

void Environment::add_random_boids(int num_boids)
{
    std::random_device rd;  // random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_real_distribution<double> dis_x(0, max_x); // gen x coord
    std::uniform_real_distribution<double> dis_y(0, max_y); // gen y coord
    std::uniform_real_distribution<double> dis_v(0, 1);
    std::uniform_real_distribution<double> dis_max_v(0.3, 0.5);

    for (int i = 0; i < num_boids; i++)
    {
        // generate a random position
        double x_pos = dis_x(gen);
        double y_pos = dis_y(gen);
        Pos2D boid_pos(x_pos, y_pos);

        double x_vel = dis_v(gen);
        double y_vel = dis_v(gen);
        Vec2D boid_vel(x_vel, y_vel);
        double max_velocity = dis_max_v(gen);

        Boid boid(boid_pos, boid_vel, 50, 10, max_velocity);

        boids.push_back(boid);
    }
}

std::vector<Boid>& Environment::get_boids()
{
    return boids;
}

bool Environment::is_out_of_bounds(Boid& boid)
{
    Pos2D b_pos = boid.get_position();
    return b_pos.get_x() >= max_x || b_pos.get_y() >= max_y 
            || b_pos.get_x() < 0 || b_pos.get_y() < 0;
}

std::ostream& operator<<(std::ostream& os, const Environment& env)
{
    os << "{ max_x = " << env.max_x << "; max_y = " << env.max_y << " }\n";
    return os;
}

