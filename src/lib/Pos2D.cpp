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

Vec2D Pos2D::operator-(const Pos2D& other) const
{
    return Vec2D(x - other.get_x(), y - other.get_y());
}

Pos2D& Pos2D::operator+=(const Pos2D& other)
{
    this->x += other.get_x();
    this->y += other.get_y();

    return *this;
}

Pos2D Pos2D::operator+(const Vec2D& delta) const
{
    Pos2D res(x + delta.get_x(), y + delta.get_y());
    return res;
}

bool Pos2D::operator==(const Pos2D& other) const
{
    return this->x == other.get_x() && this->y == other.get_y();
}


double Pos2D::distance_to(const Pos2D& other) const
{
    return (*this - other).norm();
}

