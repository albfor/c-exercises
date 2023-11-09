#include <math.h>
#include <stdio.h>

int main(void)
{
    double moves_needed = pow(2, 64) - 1;
    printf("moves needed: %E\n", moves_needed);
    printf("in years: %E\n", moves_needed / 60 / 60 / 24 / 365);

    return 0;
}

