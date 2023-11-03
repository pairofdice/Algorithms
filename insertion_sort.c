#include <stddef.h>
#include <stdio.h>
#define N 12


void insertion_sort(int* arr, size_t size) {
    for (size_t i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main () {
    int arr[N] = { 5, 6, 12, 3, 9, 7, 4, 10, 1, 2, 11, 8 };

    printf("Array: ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    insertion_sort(arr, N);

    printf("Array: ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

