#pragma once

/**
 * Author: Ethan Graham
 */

#include "Vec2D.hpp"

/**
 * @brief defines a 2D position with an X and a Y coordinate
 */
class Pos2D: private Vec2D
{
public:
    Pos2D(double x, double y);
    Pos2D();
    /**
     * @brief computes the Euclidean distance between current pos and another
     *
     * @param other another Pos2D
     *
     * @returns dist(this, other)
     */
    double distance_to(const Pos2D& other) const;

    /**
     * @brief returns the vector difference between two points
     *
     * @param other another Pos2D
     */
    Vec2D operator-(const Pos2D& other) const;

    /**
     * @brief += operator, used for center of mass calculation
     *
     * @param other the Pos2D to add
     *
     * @returns the updated position
     */
    Pos2D& operator+=(const Pos2D& other);

    Pos2D operator+(const Vec2D& delta) const;

    /**
     * @brief compares two positions for equality
     */
    bool operator==(const Pos2D& other) const;
};

