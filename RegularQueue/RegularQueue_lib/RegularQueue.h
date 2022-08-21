#ifndef REGULARQUEUE_REGULARQUEUE_H
#define REGULARQUEUE_REGULARQUEUE_H

struct RegularQueue;    // forwared declared for encapsulation
RegularQueue* RegularQueue__create(int size);
void RegularQueue__destroy(RegularQueue* self);
int RegularQueue__is_empty();
int RegularQueue__is_full();
void RegularQueue__enqueue(int value);
int RegularQueue__dequeue();
int RegularQueue__peek();

#endif //REGULARQUEUE_REGULARQUEUE_H
