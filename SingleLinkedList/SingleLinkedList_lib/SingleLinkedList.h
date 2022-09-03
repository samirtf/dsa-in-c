#ifndef TESTINGSTACK_STACK_H
#define TESTINGSTACK_STACK_H

typedef struct Node_st Node_st;
struct Node_st;
typedef struct SingleLinkedList_st SingleLinkedList_st;
struct SingleLinkedList_st; // forwarded declared for encapsulation
SingleLinkedList_st* SingleLinkedList__create(int size);
void SingleLinkedList__destroy(SingleLinkedList_st* self);
int SingleLinkedList__is_empty(SingleLinkedList_st* self);
int SingleLinkedList__is_full(SingleLinkedList_st* self);
int SingleLinkedList__add(SingleLinkedList_st* self, int value);
int SingleLinkedList__remove(SingleLinkedList_st* self);
int SingleLinkedList__first(SingleLinkedList_st* self);
int SingleLinkedList__last(SingleLinkedList_st* self);
int SingleLinkedList__max_size(SingleLinkedList_st* self);
int SingleLinkedList__size(SingleLinkedList_st* self);
void SingleLinkedList__display(SingleLinkedList_st* self);

#endif //TESTINGSTACK_STACK_H
