#include <stdio.h>
#include <string.h>
#include "my_math.h"

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while (0)
#define _verify(test) do { int r = test(); tests_run++; if (r) return r; } while (0)

int count_digits_1() {
    _assert(digits(1) == 1);
    _assert(digits(9) == 1);
    _assert(digits(10) == 2);
    _assert(digits(99) == 2);
    _assert(digits(239899) == 6);
    return 0;
}

int count_digits_2() {
    _assert(digits(-1) == 1);
    _assert(digits(-10) == 2);
    _assert(digits(-100) == 3);
    return 0;
}


int powerof_1() {
    _assert(8 == powerof(2, 3));
    _assert(28561 == powerof(13, 4));
    return 0;
}

int powerof_2() {
    _assert(1 == powerof(-1, 2));
    _assert(-1 == powerof(-1, 3));
    _assert(0.25 == powerof(2, -2));
    _assert(-0.125 == powerof(-2, -3));
    return 0;
}

int all_tests() {
    _verify(count_digits_1);
    _verify(count_digits_2);
    _verify(powerof_1);
    _verify(powerof_2);
    return 0;
}

int main(void)
{
    int result = all_tests(); 

    if (result == 0) {
        printf("PASSED\n");
    }

    printf("%d tests run.\n", tests_run);

    return 0;
}

