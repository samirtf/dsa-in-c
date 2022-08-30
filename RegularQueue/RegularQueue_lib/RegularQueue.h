#ifndef REGULARQUEUE_REGULARQUEUE_H
#define REGULARQUEUE_REGULARQUEUE_H

typedef struct RegularQueue_st RegularQueue_st;
struct RegularQueue_st;    // forwared declared for encapsulation
RegularQueue_st* RegularQueue__create(int size);
void RegularQueue__destroy(RegularQueue_st* self);
int RegularQueue__is_empty(RegularQueue_st* self);
int RegularQueue__is_full(RegularQueue_st* self);
void RegularQueue__enqueue(RegularQueue_st* self, int value);
int RegularQueue__dequeue(RegularQueue_st* self);
int RegularQueue__peek(RegularQueue_st* self);
int RegularQueue__max_size(RegularQueue_st* self);
int RegularQueue__size(RegularQueue_st* self);
void RegularQueue__display(RegularQueue_st* self);

#endif //REGULARQUEUE_REGULARQUEUE_H
