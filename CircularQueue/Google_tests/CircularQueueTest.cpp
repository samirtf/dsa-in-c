#include "gtest/gtest.h"

extern "C" {
    #include "CircularQueue.h"
}

TEST(ConstructionSuite, NullIfCreatesWithNegativeSize) {
    CircularQueue_st *queue = CircularQueue__create(-1);
    EXPECT_EQ(NULL, queue);
    CircularQueue__destroy(queue);
}

TEST(ConstructionSuite, NullIfCreatesWithZeroSize){
    CircularQueue_st *queue = CircularQueue__create(0);
    EXPECT_EQ(NULL, queue);
    CircularQueue__destroy(queue);
}

TEST(ConstructionSuite, QueueInitsWithNoElements){
    CircularQueue_st *queue = CircularQueue__create(5);
    EXPECT_TRUE(CircularQueue__is_empty(queue));
    CircularQueue__destroy(queue);
}

TEST(ConstructionSuite, QueueInitsNotFull){
    CircularQueue_st *queue = CircularQueue__create(5);
    EXPECT_FALSE(CircularQueue__is_full(queue));
    CircularQueue__destroy(queue);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsOne){
    CircularQueue_st *queue = CircularQueue__create(1);
    EXPECT_EQ(1, CircularQueue__max_size(queue));
    CircularQueue__destroy(queue);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsTwo){
    CircularQueue_st *queue = CircularQueue__create(2);
    EXPECT_EQ(2, CircularQueue__max_size(queue));
    CircularQueue__destroy(queue);
}

TEST(ConstructionSuite, QueueHasNoElements){
    CircularQueue_st *queue = CircularQueue__create(3);
    EXPECT_EQ(0, CircularQueue__size(queue));
    CircularQueue__destroy(queue);
}

TEST(SizeSuite, OneElement){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    EXPECT_EQ(1, CircularQueue__size(queue));
    CircularQueue__destroy(queue);
}

TEST(SizeSuite, TwoElements){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    EXPECT_EQ(2, CircularQueue__size(queue));
    CircularQueue__destroy(queue);
}

TEST(SizeSuite, ThreeElements){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    EXPECT_EQ(3, CircularQueue__size(queue));
    CircularQueue__destroy(queue);
}

TEST(SizeSuite, FourElements){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    CircularQueue__enqueue(queue, 45);
    EXPECT_EQ(3, CircularQueue__size(queue));
    CircularQueue__destroy(queue);
}

TEST(EnqueueSuite, OneElement){
    CircularQueue_st *queue = CircularQueue__create(3);
    int position = CircularQueue__enqueue(queue, 42);
    EXPECT_EQ(0, position);
    CircularQueue__destroy(queue);
}

TEST(EnqueueSuite, TwoElements){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    int position = CircularQueue__enqueue(queue, 43);
    EXPECT_EQ(1, position);
    CircularQueue__destroy(queue);
}

TEST(EnqueueSuite, ThreeElements){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    int position = CircularQueue__enqueue(queue, 44);
    EXPECT_EQ(2, position);
    CircularQueue__destroy(queue);
}

TEST(EnqueueSuite, FourElementsAndExceedsMaximum){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    int position = CircularQueue__enqueue(queue, 45);
    EXPECT_EQ(NULL, position);
    CircularQueue__destroy(queue);
}

TEST(DequeueSuite, RemoveOne){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    int element = CircularQueue__dequeue(queue);
    EXPECT_EQ(42, element);
    CircularQueue__destroy(queue);
}

TEST(DequeueSuite, RemoveTwo){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    CircularQueue__dequeue(queue);
    int element = CircularQueue__dequeue(queue);
    EXPECT_EQ(43, element);
    CircularQueue__destroy(queue);
}

TEST(DequeueSuite, RemoveThree){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    CircularQueue__dequeue(queue);
    CircularQueue__dequeue(queue);
    int element = CircularQueue__dequeue(queue);
    EXPECT_EQ(44, element);
    CircularQueue__destroy(queue);
}

TEST(DequeueSuite, DequeueOnEmptyQueue){
    CircularQueue_st *queue = CircularQueue__create(3);
    CircularQueue__enqueue(queue, 42);
    CircularQueue__enqueue(queue, 43);
    CircularQueue__enqueue(queue, 44);
    CircularQueue__dequeue(queue);
    CircularQueue__dequeue(queue);
    CircularQueue__dequeue(queue);
    int element = CircularQueue__dequeue(queue);
    EXPECT_EQ(NULL, element);
    CircularQueue__destroy(queue);
}

TEST(CircularQueueTestSuite, TestIfQueueIsNotEmpty){
    CircularQueue_st *queue = CircularQueue__create(5);
    EXPECT_TRUE(CircularQueue__is_empty(queue));
    CircularQueue__enqueue(queue, 1);
    printf("Peek: %d", CircularQueue__peek(queue));
    EXPECT_FALSE(CircularQueue__is_empty(queue));
    CircularQueue__destroy(queue);
}

TEST(CircularQueueTestSuite, TestaSeRetornaQuatro) {
    CircularQueue_st *queue = CircularQueue__create(5);
    EXPECT_TRUE(CircularQueue__is_empty(queue));
    CircularQueue__enqueue(queue, 1);
    EXPECT_FALSE(CircularQueue__is_empty(queue));
    int element = CircularQueue__dequeue(queue);
    EXPECT_EQ(1, element);
    EXPECT_TRUE(CircularQueue__is_empty(queue));
    CircularQueue__destroy(queue);
}