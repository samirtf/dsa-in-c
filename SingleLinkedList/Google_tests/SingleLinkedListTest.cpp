#include "gtest/gtest.h"

extern "C" {
    #include "SingleLinkedList.h"
}

TEST(ConstructionSuite, NullIfCreatesWithNegativeSize) {
    SingleLinkedList_st *list = SingleLinkedList__create(-1);
    EXPECT_EQ(NULL, list);
    SingleLinkedList__destroy(list);
}

TEST(ConstructionSuite, NullIfCreatesWithZeroSize){
    SingleLinkedList_st *list = SingleLinkedList__create(0);
    EXPECT_EQ(NULL, list);
    SingleLinkedList__destroy(list);
}

TEST(ConstructionSuite, ListInitsWithNoElements){
    SingleLinkedList_st *list = SingleLinkedList__create(5);
    EXPECT_TRUE(SingleLinkedList__is_empty(list));
    SingleLinkedList__destroy(list);
}

TEST(ConstructionSuite, ListInitsNotFull){
    SingleLinkedList_st *list = SingleLinkedList__create(5);
    EXPECT_FALSE(SingleLinkedList__is_full(list));
    SingleLinkedList__destroy(list);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsOne){
    SingleLinkedList_st *list = SingleLinkedList__create(1);
    EXPECT_EQ(1, SingleLinkedList__max_size(list));
    SingleLinkedList__destroy(list);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsTwo){
    SingleLinkedList_st *list = SingleLinkedList__create(2);
    EXPECT_EQ(2, SingleLinkedList__max_size(list));
    SingleLinkedList__destroy(list);
}

TEST(ConstructionSuite, QueueHasNoElements){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    EXPECT_EQ(0, SingleLinkedList__size(list));
    SingleLinkedList__destroy(list);
}

TEST(SizeSuite, OneElement){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    SingleLinkedList__add(list, 42);
    EXPECT_EQ(1, SingleLinkedList__size(list));
    SingleLinkedList__destroy(list);
}

TEST(SizeSuite, TwoElements){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    SingleLinkedList__add(list, 42);
    SingleLinkedList__add(list, 43);
    EXPECT_EQ(2, SingleLinkedList__size(list));
    SingleLinkedList__destroy(list);
}

TEST(SizeSuite, ThreeElements){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    SingleLinkedList__add(list, 42);
    SingleLinkedList__add(list, 43);
    SingleLinkedList__add(list, 44);
    EXPECT_EQ(3, SingleLinkedList__size(list));
    SingleLinkedList__destroy(list);
}

TEST(SizeSuite, FourElements){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    SingleLinkedList__add(list, 42);
    SingleLinkedList__add(list, 43);
    SingleLinkedList__add(list, 44);
    SingleLinkedList__add(list, 45);
    EXPECT_EQ(3, SingleLinkedList__size(list));
    SingleLinkedList__destroy(list);
}

TEST(EnqueueSuite, OneElement){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    int position = SingleLinkedList__add(list, 42);
    EXPECT_EQ(0, position);
    SingleLinkedList__destroy(list);
}

TEST(EnqueueSuite, TwoElements){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    SingleLinkedList__add(list, 42);
    int position = SingleLinkedList__add(list, 43);
    EXPECT_EQ(1, position);
    SingleLinkedList__destroy(list);
}

TEST(EnqueueSuite, ThreeElements){
    SingleLinkedList_st *list = SingleLinkedList__create(3);
    SingleLinkedList__add(list, 42);
    SingleLinkedList__add(list, 43);
    int position = SingleLinkedList__add(list, 44);
    EXPECT_EQ(2, position);
    SingleLinkedList__destroy(list);
}

TEST(EnqueueSuite, FourElementsAndExceedsMaximum){
    SingleLinkedList_st *queue = SingleLinkedList__create(3);
    SingleLinkedList__add(queue, 42);
    SingleLinkedList__add(queue, 43);
    SingleLinkedList__add(queue, 44);
    int position = SingleLinkedList__add(queue, 45);
    EXPECT_EQ(NULL, position);
    SingleLinkedList__destroy(queue);
}

TEST(DequeueSuite, RemoveOne){
    SingleLinkedList_st *queue = SingleLinkedList__create(3);
    SingleLinkedList__add(queue, 42);
    SingleLinkedList__add(queue, 43);
    SingleLinkedList__add(queue, 44);
    int element = SingleLinkedList__remove(queue);
    EXPECT_EQ(42, element);
    SingleLinkedList__destroy(queue);
}