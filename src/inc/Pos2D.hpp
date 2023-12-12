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
     * @return dist(this, other)
     */
    double distance_to(const Pos2D& other) const;

    /**
     * @brief returns the vector difference between two points
     *
     * @param other another Pos2D
     */
    Vec2D operator-(const Pos2D& other) const;
};

