#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 99

void fill_arr(int *arr, int len);
void print_arr(int *arr, int len);
bool find(int value, int *arr, int len);
int get_rand_range(int start, int end);

int main(void)
{
    int len = 10;
    int arr[len];
    srand(time(NULL));

    fill_arr(arr, len);
    print_arr(arr, len);

    return 0;
}

/**
 * fill @arr with unique random integers in the range 
 */
void fill_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        // keep reading random numbers until we find somthing that doesn't 
        // already exist in the array
        while(find(arr[i] = get_rand_range(MIN, MAX), arr, i)); 
    }
}

/**
 * @return a random integer in the inclusive range @start to @end.
 */
int get_rand_range(int start, int end)
{
    return rand() % (end + 1 - start) + start;
}

/**
 * @value to search for
 * @arr array to search
 * @len length of array at @arr 
 * @return true if @value is found in @arr
 */
bool find(int value, int *arr, int len)
{
    for (int i = 0; i < len; i++)
        if (arr[i] == value)
            return true;

    return false;
}

void print_arr(int *arr, int len)
{
    printf("arr: { ");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d }\n", arr[len - 1]);
}

