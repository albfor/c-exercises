#include <stdio.h>

int digits(int num) {
    if (num < 10)
        return 1;
    return 1 + digits(num / 10);
}

long powerof(int x, int y) {
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    return x * powerof(x, --y);
}

int main(void)
{

    printf("%d\n", digits(438456));
    printf("%ld\n", powerof(4, 4));

    return 0;
}
