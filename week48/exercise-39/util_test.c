#include "util.h"
#include <assert.h>
#include <stdio.h>

int main(void)
{
    assert(gcd(8, 12) == 4);
    assert(lcm(4, 6) == 12);
    char str[] = "jsaNSHosAlPWnSJq";
    sort_string(str);
    assert(!strcmp(str, "AaHJjlNnoPqSSssW"));

    printf("All tests passed\n");

    return 0;
}
