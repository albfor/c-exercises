/**
 * @file main.c
 * @author Albin Forberg
 * @brief Some simple array utilities.
 * @date 2023-11-15
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 99

void fill_arr(int *arr, int len);
void print_arr(int *arr, int len);
bool find(int value, int *arr, int len);
int get_rand_in_range(int start, int end);

/**
 * @breif Fill arr with random integers between MAX and MIN.
 * @param arr pointer to an integer array
 * @param len length of arr
 */
void fill_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        // keep reading random numbers until we find somthing that doesn't 
        // already exist in the array
        while(find(arr[i] = get_rand_in_range(MIN, MAX), arr, i)); 
    }
}

/**
 * @brief This function returns a random integer in a given range.
 * @param start inclusive beginning of range.
 * @param end inclusive end of range.
 * @return Returns a random integer in the range start..end.
 */
int get_rand_in_range(int start, int end)
{
    return rand() % (end + 1 - start) + start;
}

/**
 * @param value to search for.
 * @param arr array to search.
 * @param len length of arr.
 * @return true if value is found in arr.
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

