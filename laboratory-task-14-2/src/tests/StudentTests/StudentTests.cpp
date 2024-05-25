#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Student/Student.hpp"

TEST(CONSTRUCTOR_TEST, DEFAULT_CONSTRUCTOR)
{
    Student obj;

    EXPECT_EQ(obj.getCourse(), 1);
    EXPECT_EQ(obj.getGroup(), 1);
}

TEST(CONSTRUCTOR_TEST,CONSTRUCTOR_BY_PARAMETERS)
{
    Student obj("Rostislav",1,7121);

    EXPECT_STREQ(obj.getFullName(), "Rostislav");
    EXPECT_EQ(obj.getCourse(), 1);
    EXPECT_EQ(obj.getGroup(), 7121);
}