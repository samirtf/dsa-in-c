#include "gtest/gtest.h"

extern "C" {
    #include "RegularQueue.h"
}

TEST(RegularQueueTestSuite, TestIfQueueHasSizeEqualToFive){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_EQ(5, RegularQueue__size(queue));
    RegularQueue__destroy(queue);
}

TEST(RegularQueueTestSuite, TestIfQueueIsEmpty){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_TRUE(RegularQueue__is_empty(queue));
    RegularQueue__destroy(queue);
}

TEST(RegularQueueTestSuite, TestIfQueueIsFull){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_FALSE(RegularQueue__is_full(queue));
    RegularQueue__destroy(queue);
}

TEST(RegularQueueTestSuite, TestIfQueueIsNotEmpty){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_TRUE(RegularQueue__is_empty(queue));
    RegularQueue__enqueue(queue, 1);
    printf("Peek: %d", RegularQueue__peek(queue));
    EXPECT_FALSE(RegularQueue__is_empty(queue));
    RegularQueue__destroy(queue);
}

TEST(RegularQueueTestSuite, TestaSeRetornaQuatro){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_TRUE(RegularQueue__is_empty(queue));
    RegularQueue__enqueue(queue, 1);
    EXPECT_FALSE(RegularQueue__is_empty(queue));
    int element = RegularQueue__dequeue(queue);
    EXPECT_EQ(1, element);
    EXPECT_TRUE(RegularQueue__is_empty(queue));
    RegularQueue__destroy(queue);
}