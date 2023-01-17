#include <stdio.h>
#define SIZE 10

void bubble_sort(int * const data, size_t size);
void sort(int array [], int size);


int main1() {
    int data [SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}

int main2() {
    int data [SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(data, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}

int main() {
    main1();
    puts("");
    main2();
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

void bubble_sort(int * const data, size_t size) {
    void swap(int *firstPtr, int *secondPtr);
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (data[j] > data[j + 1]) {
                swap( &data[j], &data[j + 1]);
            }
        }
    }
}

void swap(int *firstPtr, int *secondPtr) {
    int hold = *firstPtr;
    *firstPtr = *secondPtr;
    *secondPtr = hold;
}
