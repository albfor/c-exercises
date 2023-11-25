#include <stdio.h>
#include "my_math.h"

int digits(int num) {
    if (num < 10 && num > -10)
        return 1;
    return 1 + digits(num / 10);
}

double powerof(int x, int y) {
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    if (y < 0)
        return (1.0 / x) * powerof(x, ++y);
    return x * powerof(x, --y);
}

