#include <stdio.h>
#define SIZE 10

void sort(int array [], int size);


int main() {
    int data [SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}

void sort(int array [], int size) {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int hold = array[j];
                array[j] = array[j + 1];
                array[j + 1] = hold;
            }
        }
    }
}