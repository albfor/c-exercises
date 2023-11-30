#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10
#define RANGE 100

void swap(int *a, int *b);
void bubble_sort(int *arr, int len);
void print_arr(int *arr, int len);

int main(void)
{
    // int *arr = (int *) malloc(SIZE * sizeof(int));
    int arr[SIZE];
    srand(time(NULL));

    int *n = arr + SIZE;                    // first address after arr
    for (int *ptr = arr; ptr < n; ptr++) {
        *ptr = rand() % RANGE;                // read random values into arr, exclusive range
    }

    printf("unsorted array: ");
    print_arr(arr, SIZE);                         // print unsorted arr
    bubble_sort(arr, SIZE);                       // sort
    printf("\n  sorted array: ");
    print_arr(arr, SIZE);                         // print sorted arr

    return 0;
}

/**
 * Swap values found att address a and b.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Sort @arr in ascending order using bubble sort
 * using pointers because of reasons.
 */
void bubble_sort(int *arr, int len)
{
    bool swapped;
    for (int i = 0; i < len - 1; i++) {
        swapped = false;
        int *n = arr + len - 1 - i;
        for (int *ptr = arr; ptr < n; ptr++) {
            if (*ptr > *(ptr + 1)) {
                swap(ptr, ptr + 1);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

/**
 * Print @arr to stdout
 */
void print_arr(int *arr, int len)
{
    int *n = arr + len;
    for (int *ptr = arr; ptr < n; ptr++) {
        printf("%2d ", *ptr);
    }
}

