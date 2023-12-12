/**
 * Function definitions for Pos2D class
 * Author: Ethan Graham
 */

#include "../inc/Pos2D.hpp"

#define DEFAULT_X 0
#define DEFAULT_Y 0

Pos2D::Pos2D(double x, double y) : Vec2D(x, y)
{
    this->x = x;
    this->y = y;
}

Pos2D::Pos2D() : Vec2D()
{
    Pos2D(0, 0);
}

Vec2D Pos2D::operator-(const Pos2D& other)
{
    return Vec2D(x - other.get_x(), y - other.get_y());
}


double Pos2D::distance_to(const Pos2D& other)
{
    return (*this - other).norm();
}

