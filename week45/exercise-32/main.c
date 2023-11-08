#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef bool (*compare_t)(int, int);

void fill_arr(int len, int *arr);
void print_arr(int len, int *arr);
void swap(int *a, int *b);
void sort(int len, int *arr, compare_t compare);
bool compare_asc(int a, int b);
bool compare_desc(int a, int b);

int main(void)
{
    srand(time(NULL));
    int arr[5];

    fill_arr(5, arr);
    print_arr(5, arr);

    sort(5, arr, compare_asc);
    print_arr(5, arr);

    sort(5, arr, compare_desc);
    print_arr(5, arr);

    return 0;
}

void print_arr(int len, int *arr)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", *arr++);
    }
    printf("\n");
}

void fill_arr(int len, int *arr)
{
    for (int i = 0; i < len; i++) {
        *arr++ = rand() % 100;
    }
}

void sort(int len, int *arr, compare_t compare)
{
    bool swapped;
    for (int i = 0; i < len; i++) {
        swapped = false;
        for (int j = 0; j < len - 1 - i; j++) {
            if (compare(*(arr + j), *(arr + j + 1))) {
                swap(arr + j, arr + j + 1);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

bool compare_asc(int a, int b)
{
    return a > b;
}

bool compare_desc(int a, int b)
{
    return a < b;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

