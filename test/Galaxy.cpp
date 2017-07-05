/**
 * @file   test/Galaxy.cpp
 * @brief  Unit tests for class Galaxy.
 * @date   July 4th, 2017
 * @author Bernd Doser <bernd.doser@h-its.org>
 */

#include "Galaxy.h"
#include "gtest/gtest.h"

TEST(GalaxyTest, mass)
{
    Galaxy galaxy {{
      Star{{0.0, 0.0, 0.0}, 2.0},
      Star{{1.0, 0.0, 0.0}, 5.0}
    }};

    EXPECT_EQ(galaxy.get_mass(), 7.0);
}
