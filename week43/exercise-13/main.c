#include <stdio.h>

int main(void)
{
    // print all numbers ending with 7 bellow 1000
    for (int i = 7; i < 1000; i += 10)
        printf("%d, ", i);

    printf("\n");

    return 0;
}
