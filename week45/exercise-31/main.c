#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_array(int len, int *arr);
void print_array(int len, int *arr);
void print_array2d(int row, int col, int (*arr)[col]);

int main(void)
{
    srand(time(NULL));
    int len = 10;
    int arr[len];
    fill_array(len, arr);
    print_array(len, arr);

    int arr2[2][3] = {{1,2,3}, {4,5,6}};
    print_array2d(2, 3, arr2);

    return 0;
}

void fill_array(int len, int *arr)
{
    for (int i = 0; i < len; i++) {
        *arr++ = rand() % 50;
    }
}

void print_array(int len, int *arr)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", *arr++);
    }
    printf("\n");
}

void print_array2d(int row, int col, int (*arr)[col])
{
    for (int i = 0; i < row; i++) {
        print_array(col, *arr++);
    }
}

