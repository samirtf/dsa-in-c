#include "gtest/gtest.h"

extern "C" {
    #include "RegularQueue.h"
}


TEST(ConstructionSuite, NullIfCreatesWithNegativeSize){
    RegularQueue_st *queue = RegularQueue__create(-1);
    EXPECT_EQ(NULL, queue);
    RegularQueue__destroy(queue);
}

TEST(ConstructionSuite, NullIfCreatesWithZeroSize){
    RegularQueue_st *queue = RegularQueue__create(0);
    EXPECT_EQ(NULL, queue);
    RegularQueue__destroy(queue);
}

TEST(ConstructionSuite, QueueInitsWithNoElements){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_TRUE(RegularQueue__is_empty(queue));
    RegularQueue__destroy(queue);
}

TEST(ConstructionSuite, QueueInitsNotFull){
    RegularQueue_st *queue = RegularQueue__create(5);
    EXPECT_FALSE(RegularQueue__is_full(queue));
    RegularQueue__destroy(queue);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsOne){
    RegularQueue_st *queue = RegularQueue__create(1);
    EXPECT_EQ(1, RegularQueue__max_size(queue));
    RegularQueue__destroy(queue);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsTwo){
    RegularQueue_st *queue = RegularQueue__create(2);
    EXPECT_EQ(2, RegularQueue__max_size(queue));
    RegularQueue__destroy(queue);
}

TEST(ConstructionSuite, QueueHasNoElements){
    RegularQueue_st *queue = RegularQueue__create(3);
    EXPECT_EQ(0, RegularQueue__size(queue));
    RegularQueue__destroy(queue);
}

TEST(EnqueueSuite, Queue){
    RegularQueue_st *queue = RegularQueue__create(3);
    RegularQueue__enqueue(queue, 42);
    EXPECT_EQ(1, RegularQueue__size(queue));
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