#ifndef CIRCULARQUEUE_CIRCULARQUEUE_H
#define CIRCULARQUEUE_CIRCULARQUEUE_H

typedef struct CircularQueue_st CircularQueue_st;
struct CircularQueue_st;    // forwared declared for encapsulation
CircularQueue_st* CircularQueue__create(int size);
void CircularQueue__destroy(CircularQueue_st* self);
int CircularQueue__is_empty(CircularQueue_st* self);
int CircularQueue__is_full(CircularQueue_st* self);
int CircularQueue__enqueue(CircularQueue_st* self, int value);
int CircularQueue__dequeue(CircularQueue_st* self);
int CircularQueue__peek(CircularQueue_st* self);
int CircularQueue__max_size(CircularQueue_st* self);
int CircularQueue__size(CircularQueue_st* self);
void CircularQueue__display(CircularQueue_st* self);

#endif //CIRCULARQUEUE_CIRCULARQUEUE_H
