#include "../inc/Vec2D.hpp"
#include <cmath>

Vec2D::Vec2D(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vec2D::Vec2D()
{
    Vec2D(0, 0);
}

double Vec2D::get_x() const
{
    return x;
}

double Vec2D::get_y() const
{
    return y;
}

Vec2D Vec2D::operator+(const Vec2D& other) const
{
    Vec2D res(this->x + other.get_x(), this->y + other.get_y());
    return res;
}

Vec2D Vec2D::operator-(const Vec2D& other) const
{
    Vec2D res(this->x - other.get_x(), this->y - other.get_y());
    return res;
}

Vec2D& Vec2D::operator+=(const Vec2D& other)
{
    this->x += other.get_x();
    this->y += other.get_y();

    return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& other)
{
    this->x -= other.get_x();
    this->y -= other.get_y();

    return *this;
}

Vec2D& Vec2D::operator*=(const double lambda)
{
    x *= lambda;
    y *= lambda;

    return *this;
}

bool Vec2D::operator==(const Vec2D& other) const
{
    return this->x == other.get_x() && this->y == other.get_y();
}

bool Vec2D::operator!=(const Vec2D& other) const
{
    return !(*this == other);
}

double Vec2D::norm() const
{
    return std::sqrt(this->x*this->x + this->y*this->y);
}


std::ostream& operator<<(std::ostream& os, const Vec2D& vec)
{
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

