#include <limits.h>
#include <stdio.h>

int max(int *arr, int len);
int find(int value, int *arr, int len);
float avg(int *arr, int len);

int main(void)
{
    int arr[5] = {1,2,3,4,6};
    printf("max: %d\n", max(arr, 5));
    printf("avg: %.2f\n", avg(arr, 5));
    printf("find 3: %d\n", find(3, arr, 5));
    printf("find 5: %d\n", find(5, arr, 5));

    return 0;
}

float avg(int *arr, int len)
{
    float total = 0.0f;
    for (int i = 0; i < len; i++) {
        total += arr[i];
    }
    return total / len;
}

int max(int *arr, int len)
{
    int max = INT_MIN;
    for (int i = 0; i < len; i++) {
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int find(int value, int *arr, int len)
{
    for (int i = 0; i < len; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

