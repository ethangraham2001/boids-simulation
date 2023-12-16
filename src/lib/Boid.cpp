#include "../inc/Vec2D.hpp"
#include "../inc/Pos2D.hpp"
#include "../inc/Boid.hpp"


Boid::Boid(Pos2D init_pos, Vec2D init_vel, \
            double range_align, double range_avoid, double max_velocity)
{
    this->position    = init_pos;
    this->velocity    = init_vel;
    this->range_align = range_align;
    this->range_avoid = range_avoid;
    this->max_velocity= max_velocity;
}

double Boid::distance_to(const Boid& other) const
{
    return this->position.distance_to(other.get_position());
}


Pos2D Boid::perceived_center_of_mass(std::vector<Boid>& boids)
{
    Pos2D center_of_mass(0, 0);
    int ctr = 0;
    for (auto b: boids)
    {
        if (position != b.get_position() && this->distance_to(b) < range_align)
        {
            center_of_mass += b.get_position();
            ctr++;
        }
    }
    center_of_mass *= (1.0 / ctr);
    return center_of_mass;
}

Vec2D Boid::compute_vec_rule1(const Pos2D& center_of_mass)
{
    return center_of_mass - this->position;
}

Vec2D Boid::compute_vec_rule2(const std::vector<Boid>& boids)
{
    Vec2D res(0, 0);

    for (Boid boid : boids)
        if (this->distance_to(boid) < this->range_avoid)
            res -= (boid.position - this->position);
    return res;
}

Vec2D Boid::compute_vec_rule3(const std::vector<Boid>& boids)
{
    Vec2D res(0, 0);
    int aligned_boids = 0;
    for (Boid boid : boids)
        if (this->distance_to(boid) < this->range_align &&
            position != boid.get_position())
        {
            res += boid.get_velocity();
            aligned_boids++;
        }

    return res;
}

Pos2D Boid::get_position() const
{
    return this->position;
}

Vec2D Boid::get_velocity() const
{
    return this->velocity;
}

double Boid::get_max_velocity() const
{
    return max_velocity;
}

Pos2D Boid::set_position(const Pos2D new_position)
{
    this->position = new_position;
    return new_position;
}

Vec2D Boid::set_velocity(const Vec2D new_velocity)
{
    this->velocity = new_velocity;
    return new_velocity;
}

