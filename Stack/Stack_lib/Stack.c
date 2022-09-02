#include <stdio.h>
#include <malloc.h>
#include "Stack.h"

typedef struct Stack_st Stack_st;
struct Stack_st {
    int max_size;
    int top;
    int *stack;
};

Stack_st* Stack__create(int size) {
    if (size <= 0) {
        return NULL;
    }
    Stack_st* stack = (Stack_st*) malloc(sizeof(Stack_st));
    if (stack == NULL) {
        return NULL;
    }
    stack->max_size = size;
    stack->stack = calloc(size, sizeof(int));
    stack->top = -1;
    printf("Top: %d", stack->top);
    return stack;
}

void Stack__reset(Stack_st* self) {
    // Destructor (without deallocation).
    free(self->stack);
    self->stack = NULL;
}

void Stack__destroy(Stack_st* self) {
    if (self) {
        Stack__reset(self);
        free(self);
        self = NULL;
    }
}

int Stack__is_empty(Stack_st* self) {
    return self->top == -1;
}

int Stack__is_full(Stack_st* self) {
    return self->top == self->max_size - 1;
}

int Stack__push(Stack_st* self, int value) {
    if (Stack__is_full(self)) {
        printf("Queue is full!\n");
        return NULL;
    }
    self->stack[++self->top] = value;
    return self->top;
}

int Stack__pop(Stack_st* self) {
    if (Stack__is_empty(self)) {
        return NULL;
    }
    int element = self->stack[self->top];
    self->top--;
    return element;
}

int Stack__peek(Stack_st* self) {
    if (Stack__is_empty(self)) {
        return NULL;
    }
    return self->stack[self->top];
}

int Stack__max_size(Stack_st* self) {
    return self->max_size;
}

int Stack__size(Stack_st* self) {
    if (Stack__is_empty(self)) {
        return 0;
    }
    if (Stack__is_full(self)) {
        return self->max_size;
    }
    return self->top + 1;
}

void Stack__display(Stack_st* self) {
    for (int i = 0; i < self->max_size; ++i) {
        printf("%d ", self->stack[i]);
    }
}
