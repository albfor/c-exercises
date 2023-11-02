#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 2
#define COL_SIZE 3

int main(void)
{
    srand(time(NULL));
    int arr[ROW_SIZE][COL_SIZE];
    int size = ROW_SIZE * COL_SIZE;

    // assign random values
    for (int *ptr = (int *)arr; ptr < (int *)arr + size; ptr++) {
        *ptr = rand() % 100;
    }

    // print array
    for (int i = 0, *ptr = arr[0]; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%2d ", *ptr++);
        }
        printf("\n");
    }

    return 0;
}
