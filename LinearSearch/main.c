#include <stdio.h>
#define SIZE 10

size_t search(const int data [], int key, size_t size);

int main() {
    printf("Linear Search!\n");
    int data[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t position = search(data, 7, SIZE);
    printf("search 7; its position is %d\n", position);

    position = search(data, 11, SIZE);
    if (position == -1) {
        printf("search 11; position not found");
    }
    return 0;
}

size_t search(const int data [], int key, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == key) {
            return i;
        }
    }
    return -1;
}

