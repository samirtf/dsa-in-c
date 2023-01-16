#include <stdio.h>
#define NOT_FOUND (-1)
#define SIZE 10

size_t search(int data [], size_t size, int key);

int main() {
    printf("Binary Search!\n");
    int data [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; ++i) {
        if (i != search(data, SIZE, i+1)) {
            return -1;
        }
    }
    printf("Binary Search success!");
    return 0;
}

size_t search(int data [], size_t size, int key) {
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int middle = left + (right - left)/2;
        printf("loop: %d\n", middle);
        if (data[middle] == key) {
            return middle;
        } else if (key < data[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    return NOT_FOUND;

}

