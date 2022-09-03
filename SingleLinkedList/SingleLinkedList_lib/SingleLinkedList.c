#include <stdio.h>
#include <malloc.h>
#include "SingleLinkedList.h"

typedef struct Node_st Node_st;
struct Node_st {
    int data;
    Node_st *next;
};

typedef struct SingleLinkedList_st SingleLinkedList_st;
struct SingleLinkedList_st {
    int max_size;
    Node_st *root;
};

SingleLinkedList_st* SingleLinkedList__create(int size) {
    if (size <= 0) {
        return NULL;
    }
    SingleLinkedList_st* stack = (SingleLinkedList_st*) malloc(sizeof(SingleLinkedList_st));
    if (stack == NULL) {
        return NULL;
    }
    stack->max_size = size;
    stack->root = NULL;
    printf("Root: %p", stack->root);
    return stack;
}

void SingleLinkedList__reset(SingleLinkedList_st* self) {
    // Destructor (without deallocation).
    // TODO must iterate over items and release them
    free(self->root);
    self->root = NULL;
}

void SingleLinkedList__destroy(SingleLinkedList_st* self) {
    if (self) {
        SingleLinkedList__reset(self);
        free(self);
        self = NULL;
    }
}

int SingleLinkedList__is_empty(SingleLinkedList_st* self) {
    return self->root == NULL;
}

int SingleLinkedList__is_full(SingleLinkedList_st* self) {
    if (self->root == NULL) {
        return 0;
    }
    int size = 0;
    Node_st* current = self->root;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    printf("Size: %d\n", size);
    return size == self->max_size;
}

int SingleLinkedList__add(SingleLinkedList_st* self, int value) {
    Node_st * node = (Node_st*) malloc(sizeof(Node_st));
    node->data = value;
    node->next = NULL;
    if (self->root == NULL) {
        self->root = node;
        printf("self->root == NULL");
        return 0;
    }
    int size = 1;
    Node_st* current = self->root;
    while (current->next != NULL) {
        size++;
        current = current->next;
    }
    printf("add size: %d ", size);
    if (size == self->max_size) {
        return NULL;
    }
    current->next = node;
    return size;
}

int SingleLinkedList__remove(SingleLinkedList_st* self) {
    return NULL;
}

int SingleLinkedList__first(SingleLinkedList_st* self) {
    return NULL;
}

int SingleLinkedList__last(SingleLinkedList_st* self) {
    return NULL;
}

int SingleLinkedList__max_size(SingleLinkedList_st* self) {
    return self->max_size;
}

int SingleLinkedList__size(SingleLinkedList_st* self) {
    if (self->root == NULL) {
        return 0;
    }
    int size = 1;
    Node_st* current = self->root;
    while (current->next != NULL) {
        size++;
        current = current->next;
    }
    printf("Size: %d\n", size);
    return size;
}

void SingleLinkedList__display(SingleLinkedList_st* self) {
    for (int i = 0; i < self->max_size; ++i) {
        printf("%d ", 1);
    }
}
