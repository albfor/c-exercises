#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10                             // array size

int cmpfunc(const void* a, const void* b);  // tells qsort how to compare items
void print_arr(int arr[], int size);        // prints arr

int main(void)
{
    // init 
    int arr[SIZE];
    srand(time(NULL));

    // assign random values in the range 0..50 to the array slots
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 50;
    }

    printf("unsorted: ");
    print_arr(arr, SIZE);                   // print unsorted array
    qsort(arr, SIZE, sizeof(int), cmpfunc); // sort array
    printf("  sorted: ");
    print_arr(arr, SIZE);                   // print sorted array

    return EXIT_SUCCESS;
}

int cmpfunc(const void* a, const void* b) {
    // cast the void pointers to int pointers and then read the ints
    // return a-b for ascending order 
    return *(int*) a - *(int*) b; 
}

void print_arr(int arr[], int size) {
    for (int i = 0 ; i < size; i++) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

