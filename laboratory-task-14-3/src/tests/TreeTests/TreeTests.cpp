#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Tree/Tree.hpp"

TEST(CONSTRUCTOR_TEST, DEFAULT_CONSTRUCTOR)
{
    Tree obj;

    EXPECT_EQ(obj.getName(), "");
    EXPECT_EQ(obj.Age(), 0);
    EXPECT_EQ(obj.Type(), TypeTree::deciduous);
}

TEST(CONSTRUCTOR_TEST,CONSTRUCTOR_BY_PARAMETERS)
{
    Tree obj("Spruce", 30, TypeTree::coniferous);

    EXPECT_STREQ(obj.getName(), "Spruce");
    EXPECT_EQ(obj.Age(), 30);
    EXPECT_EQ(obj.Type(), TypeTree::coniferous);
}