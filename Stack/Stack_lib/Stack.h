#ifndef TESTINGSTACK_STACK_H
#define TESTINGSTACK_STACK_H

typedef struct Stack_st Stack_st;
struct Stack_st;    // forwarded declared for encapsulation
Stack_st* Stack__create(int size);
void Stack__destroy(Stack_st* self);
int Stack__is_empty(Stack_st* self);
int Stack__is_full(Stack_st* self);
int Stack__push(Stack_st* self, int value);
int Stack__pop(Stack_st* self);
int Stack__peek(Stack_st* self);
int Stack__max_size(Stack_st* self);
int Stack__size(Stack_st* self);
void Stack__display(Stack_st* self);

#endif //TESTINGSTACK_STACK_H
