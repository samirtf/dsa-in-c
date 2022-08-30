#include <stdio.h>
#include <malloc.h>
#include "RegularQueue.h"

typedef struct RegularQueue_st RegularQueue_st;
struct RegularQueue_st {
    int max_size;
    int head;
    int tail;
    int *queue;
};

RegularQueue_st* RegularQueue__create(int size) {
    if (size <= 0) {
        return NULL;
    }
    RegularQueue_st* result = (RegularQueue_st*) malloc(sizeof(RegularQueue_st));
    if (result == NULL) {
        return NULL;
    }
    result->max_size = size;
    result->queue = calloc(size, sizeof (int));
    result->head = -1;
    result->tail = -1;
    printf("Head: %d, Tail: %d", result->head, result->tail);
    return result;
}

void RegularQueue__reset(RegularQueue_st* self) {
    // Destructor (without deallocation).
    free(self->queue);
    self->queue = NULL;
}

void RegularQueue__destroy(RegularQueue_st* self) {
    if (self) {
        RegularQueue__reset(self);
        free(self);
        self = NULL;
    }
}

int RegularQueue__is_empty(RegularQueue_st* self) {
    return self->head == -1;
}

int RegularQueue__is_full(RegularQueue_st* self) {
    return self->head == 0 && self->tail == self->max_size - 1;
}

void RegularQueue__enqueue(RegularQueue_st* self, int value) {
    if (RegularQueue__is_full(self)) {
        printf("Queue is full!\n");
    } else {
        if (RegularQueue__is_empty(self)) {
            self->head = 0;
        }
        self->tail++;
        self->queue[self->tail] = value;
        printf("Inserted -> %d\n", value);
    }
    printf("Head: %d, Tail: %d", self->head, self->tail);
}

int RegularQueue__dequeue(RegularQueue_st* self) {
    if (RegularQueue__is_empty(self)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int element = self->queue[self->head];
        self->head++;
        if (self->head > self->tail) {
            self->head = self->tail = -1;
            // Q has only one element, so we reset the queue after deleting it.
        }
        printf("Deleted -> %d\n", element);
        return element;
    }
}

int RegularQueue__peek(RegularQueue_st* self) {
    RegularQueue__display(self);
    return self->queue[self->head];
}

int RegularQueue__max_size(RegularQueue_st* self) {
    return self->max_size;
}


int RegularQueue__size(RegularQueue_st* self) {
    return self->tail - self->head;
}

void RegularQueue__display(RegularQueue_st* self) {
    for (int i = 0; i < self->max_size; ++i) {
        printf("%d ", self->queue[i]);
    }
}
