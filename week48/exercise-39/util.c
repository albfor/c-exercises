#include "util.h"
#include <ctype.h>
#include <stdlib.h>

unsigned int gcd(unsigned int a, unsigned int b)
{
    unsigned int divisor = 1;
    for (int i = 1; i < a && i < b; i++)
    {
        if (a % i == 0 && b % i == 0)
            divisor = i;
    }
    return divisor;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int multiple = a * b;

    unsigned int i = multiple;
    while (i > a && i > b)
    {
        if (i % a == 0 && i % b == 0)
            multiple = i;
        i--;
    }

    return multiple;
}

static int compare(const void * a, const void * b)
{
    int res = tolower(*(char*) a) - tolower(*(char*) b); 
    if (res == 0) {
        return *(char*)a - *(char*)b;
    }
    return tolower(*(char*) a) - tolower(*(char*) b);
}

void sort_string(char * str)
{
    int len = strlen(str);
    qsort(str, len, 1, compare);
}
