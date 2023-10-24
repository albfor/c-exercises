#include <stdio.h>

int main(void)
{
    for (int i = 7; i < 1000; i += 10)
        printf("%d, ", i);

    printf("\n");

    return 0;
}
