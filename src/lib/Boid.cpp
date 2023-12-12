#include "../inc/Vec2D.hpp"
#include "../inc/Pos2D.hpp"
#include "../inc/Boid.hpp"

Boid::Boid(Pos2D position, Vec2D velocity, double range_avoid, \
            double range_align, double max_speed)
{
    this->position = position;
    this->velocity = velocity;
    this->range_avoid = range_avoid;
    this->range_align = range_align;
    this->max_speed = max_speed;
}

