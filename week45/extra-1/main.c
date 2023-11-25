#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int len);
int *merge(int *arrA, int lenA, int *arrB, int lenB);
void swap(int *a, int *b);

int main(void)
{
    int len1 = 5, len2 = 5;
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {0, 2, 4, 6, 8};
    int *new = merge(arr1, 5, arr2, 5);

    for (int i = 0; i < len1 + len2; i++) {
        printf("%d ", new[i]);
    }

    return 0;
}

void append(int *arr, int index, int *arrA, int indexA, int lenA) {
    while (indexA < lenA)
    {
        arr[index] = arrA[indexA];
        index++;
        indexA++;
    }
}

// merge two arrays into one sorted
// assumes they are sorted
int *merge(int *arrA, int lenA, int *arrB, int lenB)
{
    int a = 0, b = 0;
    // allocate memory for array
    int *arr = (int*)malloc((lenA + lenB) * sizeof(int));

    while (a < lenA && b < lenB)
    {
        if (arrA[a] < arrB[b]) {
            arr[a + b] = arrA[a];
            a++;
        } else {
            arr[a + b] = arrB[b];
            b++;
        }
    }

    append(arr, a + b, arrA, a, lenA);
    append(arr, a + b, arrB, b, lenB);

    return arr;
}

// insertion sort
void sort(int *arr, int len)
{
    for (int i = 1; i < len; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

// swap value 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
