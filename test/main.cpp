/**
 * @file   test/main.cpp
 * @brief  Unit tests main function for Galaxy.
 * @date   July 4th, 2017
 * @author Bernd Doser <bernd.doser@h-its.org>
 */

#include "gtest/gtest.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
