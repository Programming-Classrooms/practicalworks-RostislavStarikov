#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Product/Product.hpp"

TEST(ProductTest, ParameterizedConstructor) {
    Product p("TestProduct", 10.5, 2023);
    EXPECT_STREQ(p.getName(), "TestProduct");
    EXPECT_EQ(p.getCost(), 10.5);
    EXPECT_EQ(p.getYearOfManufacture(), 2023);
}

TEST(ProductTest, CopyConstructor) {
    Product p1("TestProduct", 10.5, 2023);
    Product p2(p1);
    EXPECT_STREQ(p2.getName(), "TestProduct");
    EXPECT_EQ(p2.getCost(), 10.5);
    EXPECT_EQ(p2.getYearOfManufacture(), 2023);
}



TEST(ProductTest, EqualityOperator) {
    Product p1("TestProduct", 10.5, 2023);
    Product p2("TestProduct", 10.5, 2023);
    EXPECT_TRUE(p1 == p2);
    Product p3("DifferentProduct", 10.5, 2023);
    EXPECT_FALSE(p1 == p3);
}
