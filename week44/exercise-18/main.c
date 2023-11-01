#include <stdio.h>
int main(void)
{
    int arr[3][3];
    printf("enter first row (d d d): ");
    scanf("%d %d %d", &arr[0][0], &arr[0][1], &arr[0][2]);
    printf("enter second row (d d d): ");
    scanf("%d %d %d", &arr[1][0], &arr[1][1], &arr[1][2]);
    printf("enter third row (d d d): ");
    scanf("%d %d %d", &arr[2][0], &arr[2][1], &arr[2][2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    
    }

    return 0;
}
