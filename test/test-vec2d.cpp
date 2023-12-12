/**
 * Author: Ethan Graham
 *
 * Tests for the Vec2D class
 */

#include "test-utility.hpp"
#include <cmath>
/**
 * @brief generates a random double between two bounds
 *
 * @param min lower bound
 * @param max upper bound
 */

#include "../src/inc/Vec2D.hpp"
#include "gtest/gtest.h"

TEST(Vec2D_test, addition_test_1)
{
    Vec2D a(1, 2);
    Vec2D b(3, 4);
    Vec2D expected(4, 6);
    EXPECT_EQ(a + b, expected);
}

TEST(Vec2D_test, addition_test_2)
{
    double min = -100.0;
    double max =  100.0;

    double a_x = generateRandomDouble(min, max);
    double a_y = generateRandomDouble(min, max);
    double b_x = generateRandomDouble(min, max);
    double b_y = generateRandomDouble(min, max);

    Vec2D a(a_x, a_y);
    Vec2D b(b_x, b_y);
    Vec2D c(a_x + b_x, a_y + b_y);
    Vec2D d(a_x - b_x, a_y - b_y);

    EXPECT_EQ(a + b, c);
    EXPECT_EQ(a - b, d);

    a += b;
    EXPECT_EQ(a, c);
}

TEST(Vec2D_test, neq_test)
{
    double min = -100.0;
    double max =  100.0;
    double a_x = generateRandomDouble(min, max);
    double a_y = generateRandomDouble(min, max);
    Vec2D a(a_x, a_y);
    Vec2D b(a_x-1, a_y-1);

    EXPECT_NE(a, b);
    b += Vec2D(1, 1);
    EXPECT_EQ(a, b);
}

TEST(Vec2D_test, multiplication_test)
{

    double min = -100.0;
    double max =  100.0;
    double lambda = generateRandomDouble(min, max);
    double a_x = generateRandomDouble(min, max);
    double a_y = generateRandomDouble(min, max);

    Vec2D a(a_x, a_y);
    a *= lambda;
    Vec2D expected(a_x*lambda, a_y*lambda);

    EXPECT_EQ(a, expected);
}

TEST(Vec2D_test, norm_test)
{
    Vec2D simple(std::sqrt(2), std::sqrt(2));
    EXPECT_EQ(simple.norm(), 2.0);

    double min = -100.0;
    double max =  100.0;
    double a_x = generateRandomDouble(min, max);
    double a_y = generateRandomDouble(min, max);
    Vec2D a(a_x, a_y);

    double norm_squared_val = a_x*a_x + a_y*a_y;

    EXPECT_NEAR(a.norm()*a.norm(), norm_squared_val, 0.01);
}


