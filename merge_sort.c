
#include <stddef.h>
#include <stdio.h>
#define N 12

void print_arr(int *arr, size_t size) {
    printf("Array: ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_merge(int *arr, int *arr_temp, size_t left, size_t middle, size_t right) {
    size_t i_smallest_left = left;          // indices
    size_t i_smallest_right = middle + 1;
    size_t i_dest = left;

    // select smaller value from the sub-arrays and push to destination
    while (i_smallest_left <= middle && i_smallest_right <= right) {
        if (arr_temp[i_smallest_left] <= arr_temp[i_smallest_right]) {
            arr[i_dest] = arr_temp[i_smallest_left];
            ++i_smallest_left;
        }
        else {
            arr[i_dest] = arr_temp[i_smallest_right];
            ++i_smallest_right;
        }
        ++i_dest;
    }

    // push the remaining already sorted values
    while (i_smallest_left <= middle) {
        arr[i_dest] = arr_temp[i_smallest_left];
        ++i_smallest_left;
        ++i_dest;
    }

    // push the remaining already sorted values
    while (i_smallest_right <= right) {
        arr[i_dest] = arr_temp[i_smallest_right];
        ++i_smallest_right;
        ++i_dest;
    }

    // update our working copy
    size_t i = left;
    while (i <= right) {
        arr_temp[i] = arr[i];
        ++i;
    }
}

// split into two
void merge_divide(int *arr, int *arr_temp, size_t left, size_t right) {
    if (left >= right)          // base case reached, recursion hit bottom, len == 1
        return ;
    size_t middle = (left + right) / 2;          // midddle point
    merge_divide(arr, arr_temp, left, middle);
    merge_divide(arr, arr_temp, middle + 1, right);
    merge_merge(arr, arr_temp, left, middle, right);
}

void merge_sort(int *arr, size_t size) {
    size_t left = 0;
    size_t right = size - 1;
    int arr_temp[N] = { };

    for (int i = 0; i < N; ++i) {
        arr_temp[i] = arr[i];
    }
    merge_divide(arr, arr_temp, left, right);
}

int main () {
    int arr[N] = { 5, 6, 12, 3, 9, 7, 4, 10, 1, 2, 11, 8 };
    int arrC[N] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int arrB[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    print_arr(arr, N);
    merge_sort(arr, N);
    print_arr(arr, N);
}

