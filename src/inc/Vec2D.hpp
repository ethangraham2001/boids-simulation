#pragma once

#include <iostream>

/**
 * @brief represents a 2D vector with X and Y components
 */
class Vec2D
{
public:
    // constructor
    Vec2D(double x, double y);
    Vec2D();

    double get_x() const;
    double get_y() const;

    /**
     * @brief defines addition of two vectors
     *
     * @param other another Vec2D
     *
     * @returns this + other
     */
    Vec2D operator+(const Vec2D& other);

    /**
     * @brief defines substraction of one vector this - other
     *
     * @param other another Vec2D
     *
     * @returns this - other
     */
    Vec2D operator-(const Vec2D& other);


    /**
     * @brief adds another Vec2D to this one; this += other
     *
     * @param another Vec2D
     *
     * @returns this + other
     */
    Vec2D& operator+=(const Vec2D& other);

    /**
     * @brief subtracts another Vec2D from this one; this -= other
     *
     * @param another Vec2D to subtract from this one
     *
     * @returns this - other
     */
    Vec2D& operator-=(const Vec2D& other);

    /**
     * @brief multiplies a vector by a constant
     */
    Vec2D& operator*=(const double lambda);

    /**
     * @brief checks for equality between two vectors
     *
     * @returns true if their components are equal, else false
     */
    bool operator==(const Vec2D& other) const;

    /**
     * @brief checks for equality between two vectors
     *
     * @returns true if their components are equal, else false
     */
    bool operator!=(const Vec2D& other) const;

    /**
     * @brief computes the vector norm of a Vec2D
     */
    double norm();

    /*
     * @brief to string method
     */
    friend std::ostream& operator<<(std::ostream& os, const Vec2D& vec); 

protected:
    double x;
    double y;
};

