#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void fill_arr(int *arr, int len);
void print_arr(int *arr, int len);
bool find(int value, int *arr, int len);

int main(void)
{
    int len = 50;
    int arr[len];
    srand(time(NULL));

    fill_arr(arr, len);
    print_arr(arr, len);

    return 0;
}

void fill_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        int temp;
        while(find(temp = (rand() % 99) + 1, arr, i)); 
        arr[i] = temp;
    }
}

bool find(int value, int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        if (arr[i] == value)
            return true;
    }
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
