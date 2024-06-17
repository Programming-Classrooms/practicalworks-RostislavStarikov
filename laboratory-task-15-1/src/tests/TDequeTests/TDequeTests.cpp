#include <stdexcept>
#include <gtest/gtest.h>
#include "src/TDeque/TDeque.hpp"

// Тест на вставку элементов
TEST(TDequeTest, InsertElements) {
    TDeque<int> deque;
    deque.InsertFront(1);
    deque.InsertRear(2);
    deque.InsertFront(0);

    EXPECT_EQ(deque.GetByIndex(0), 0);
    EXPECT_EQ(deque.GetByIndex(1), 1);
    EXPECT_EQ(deque.GetByIndex(2), 2);
}