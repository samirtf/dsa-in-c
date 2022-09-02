#include "gtest/gtest.h"

extern "C" {
    #include "Stack.h"
}

TEST(ConstructionSuite, NullIfCreatesWithNegativeSize) {
    Stack_st *stack = Stack__create(-1);
    EXPECT_EQ(NULL, stack);
    Stack__destroy(stack);
}

TEST(ConstructionSuite, NullIfCreatesWithZeroSize){
    Stack_st *stack = Stack__create(0);
    EXPECT_EQ(NULL, stack);
    Stack__destroy(stack);
}

TEST(ConstructionSuite, StackInitsWithNoElements){
    Stack_st *stack = Stack__create(5);
    EXPECT_TRUE(Stack__is_empty(stack));
    Stack__destroy(stack);
}

TEST(ConstructionSuite, StackInitsNotFull){
    Stack_st *stack = Stack__create(5);
    EXPECT_FALSE(Stack__is_full(stack));
    Stack__destroy(stack);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsOne){
    Stack_st *stack = Stack__create(1);
    EXPECT_EQ(1, Stack__max_size(stack));
    Stack__destroy(stack);
}

TEST(ConstructionSuite, MaxOfElementInQueueIsTwo){
    Stack_st *stack = Stack__create(2);
    EXPECT_EQ(2, Stack__max_size(stack));
    Stack__destroy(stack);
}

TEST(ConstructionSuite, StackHasNoElements){
    Stack_st *stack = Stack__create(3);
    EXPECT_EQ(0, Stack__size(stack));
    Stack__destroy(stack);
}

TEST(SizeSuite, OneElement){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    EXPECT_EQ(1, Stack__size(stack));
    Stack__destroy(stack);
}

TEST(SizeSuite, TwoElements){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    EXPECT_EQ(2, Stack__size(stack));
    Stack__destroy(stack);
}

TEST(SizeSuite, ThreeElements){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    EXPECT_EQ(3, Stack__size(stack));
    Stack__destroy(stack);
}

TEST(SizeSuite, FourElements){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    Stack__push(stack, 45);
    EXPECT_EQ(3, Stack__size(stack));
    Stack__destroy(stack);
}

TEST(StackSuite, OneElement){
    Stack_st *stack = Stack__create(3);
    int position = Stack__push(stack, 42);
    EXPECT_EQ(0, position);
    Stack__destroy(stack);
}

TEST(StackSuite, TwoElements){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    int position = Stack__push(stack, 43);
    EXPECT_EQ(1, position);
    Stack__destroy(stack);
}

TEST(StackSuite, ThreeElements){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    int position = Stack__push(stack, 44);
    EXPECT_EQ(2, position);
    Stack__destroy(stack);
}

TEST(StackSuite, FourElementsAndExceedsMaximum){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    int position = Stack__push(stack, 45);
    EXPECT_EQ(NULL, position);
    Stack__destroy(stack);
}

TEST(DequeueSuite, RemoveOne){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    int element = Stack__pop(stack);
    EXPECT_EQ(44, element);
    Stack__destroy(stack);
}

TEST(DequeueSuite, RemoveTwo){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    Stack__pop(stack);
    int element = Stack__pop(stack);
    EXPECT_EQ(43, element);
    Stack__destroy(stack);
}

TEST(DequeueSuite, RemoveThree){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    Stack__pop(stack);
    Stack__pop(stack);
    int element = Stack__pop(stack);
    EXPECT_EQ(42, element);
    Stack__destroy(stack);
}

TEST(DequeueSuite, DequeueOnEmptyQueue){
    Stack_st *stack = Stack__create(3);
    Stack__push(stack, 42);
    Stack__push(stack, 43);
    Stack__push(stack, 44);
    Stack__pop(stack);
    Stack__pop(stack);
    Stack__pop(stack);
    int element = Stack__pop(stack);
    EXPECT_EQ(NULL, element);
    Stack__destroy(stack);
}

TEST(CircularQueueTestSuite, TestIfQueueIsNotEmpty){
    Stack_st *stack = Stack__create(5);
    EXPECT_TRUE(Stack__is_empty(stack));
    Stack__push(stack, 1);
    printf("Peek: %d", Stack__peek(stack));
    EXPECT_FALSE(Stack__is_empty(stack));
    Stack__destroy(stack);
}

TEST(CircularQueueTestSuite, TestaSeRetornaQuatro) {
    Stack_st *stack = Stack__create(5);
    EXPECT_TRUE(Stack__is_empty(stack));
    Stack__push(stack, 1);
    EXPECT_FALSE(Stack__is_empty(stack));
    int element = Stack__pop(stack);
    EXPECT_EQ(1, element);
    EXPECT_TRUE(Stack__is_empty(stack));
    Stack__destroy(stack);
}