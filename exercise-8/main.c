/**
 * This is just to verify my calculations
 */

#include <stdio.h>
#include <stdint.h>

#define EXPRESSION (3 * j / k - 2)
#define SET_VAIRABLES   \
    {                   \
        i = 3;          \
        j = 2;          \
        k = 0;          \
    }

int main(void)
{
    int i = 0, j = 7, k = 6;
    char a = 'A', b = '3';
    int32_t x, y = 3;
    uint32_t z = 32;
    double d;

    x = EXPRESSION;
    printf("A) %d\n", x);
    
    y -= ((j << 1) & (k >> 1));
    printf("B) %d\n", y);

    x = (!(i && k) || !k) ? k + b : j + b;
    printf("C) %d\n", x);
    
    a += (b + k--) % 10;
    printf("D) %d\n", a);

    d = (double)j * 100 / --k / 3;
    printf("E) %f\n", d);

    x = -1;
    y = (x < z) ? (k < j < 0) : (b >= a < i);
    printf("F) %d\n", y);
}
