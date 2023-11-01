#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10

void swap(int *a, int *b);
void bubble_sort(int arr[]);
void print_arr(int arr[]);

int main(void)
{
    // int *arr = (int *) malloc(SIZE * sizeof(int));
    int arr[SIZE];
    srand(time(NULL));

    int *n = arr + SIZE;                    // first address after arr
    for (int *ptr = arr; ptr < n; ptr++) {
        *ptr = rand() % 100;                // read random values into arr
    }

    printf("unsorted array: ");
    print_arr(arr);                         // print unsorted arr
    bubble_sort(arr);                       // sort
    printf("\n  sorted array: ");
    print_arr(arr);                         // print sorted arr

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
 * Sort arr in ascending order using bubble sort
 * using pointers because of reasons.
 */
void bubble_sort(int arr[])
{
    bool swapped;
    for (int i = 0; i < SIZE - 1; i++) {
        swapped = false;
        int *n = arr + SIZE - 1 - i;
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
 * Print arr to stdout
 */
void print_arr(int arr[])
{
    int *n = arr + SIZE;
    for (int *ptr = arr; ptr < n; ptr++) {
        printf("%2d ", *ptr);
    }
}

