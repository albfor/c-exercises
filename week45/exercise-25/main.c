#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_arr(int *arr, int len);
void print_arr(int *arr, int len);

int main(void)
{
    int len = 10;
    int arr[len];
    srand(time(NULL));

    fill_arr(arr, len);
    print_arr(arr, len);

    return 0;
}

void fill_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        arr[i] = (rand() % 99) + 1;
    }
}

void print_arr(int *arr, int len)
{
    printf("arr: { ");
    for (int i = 0; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d }\n", arr[len - 1]);
}
