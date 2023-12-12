/**
 * Author: Ethan Graham
 *
 * Tests for the Vec2D class
 */

#include "gtest/gtest.h"
#include "../src/inc/Pos2D.hpp"
#include "test-utility.hpp"
#include <cmath>

/**
 * @brief generates a random double between two bounds
 *
 * @param min lower bound
 * @param max upper bound
 */

TEST(Pos2D_test, distance_test1)
{
    Pos2D a(0, 0);
    Pos2D b(1, 1);
    Vec2D expected(1, 1);

    EXPECT_EQ(b - a, expected);
    EXPECT_EQ(a.distance_to(b), std::sqrt(2));
}

TEST(Pos2D_test, distance_test2)
{
    double min = -100;
    double max =  100;
    double a_x = generateRandomDouble(min, max);
    double a_y = generateRandomDouble(min, max);
    double b_x = generateRandomDouble(min, max);
    double b_y = generateRandomDouble(min, max);

    Pos2D a(a_x, a_y);
    Pos2D b(b_x, b_y);
    Vec2D expected(b_x - a_x, b_y - a_y);

    EXPECT_EQ(b - a, expected);
    EXPECT_EQ(a.distance_to(b), expected.norm());
}

