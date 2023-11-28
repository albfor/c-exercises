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

/// Compare char at a and char at b alphabetically.
///
/// Example: a = 'a', b = 'b' -> (>1)
/// Example: a = 'b', b = 'A' -> (<0)
/// Example: a = 'a', b = 'A' -> (<0)
/// Example: a = 'a', b = 'a' -> (0)
///
/// @param a Pointer to a char.
/// @param b Pointer to a char.
/// @return >1 if a comes before b.
///         0  if a is equal to b.
///         <0 if a comes after b.
static int compare(const void * a, const void * b)
{
    // convert a & b to chars
    char chA = *(char *) a;
    char chB = *(char *) b;

    int res = tolower(chA) - tolower(chB); 
    if (res == 0) {
        return chA - chB;
    }
    return res;
}

void sort_string(char * str)
{
    int len = strlen(str);
    qsort(str, len, 1, compare);
}
