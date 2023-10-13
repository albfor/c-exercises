/**
 * Make a program using the printf function in stdio.h, the sizeof operator
 * and the min/max values defined in limits.h and float.h to display
 *
 * 1) Size, min and max values of char, signed char and unsigned char
 * 2) Size, min and max values of int, unsigned int, short int, unsigned short int,
 * signed long int, unsigned long int, signed long long int and usigned long long int.
 * 3) Size, min and max values of float, double and long double
 * 4) Size of enum color { RED, GREEN, BLUE, YELLOW, WHITE, BLACK };
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    printf("**********************************\n");
    printf("*               1                *\n");
    printf("**********************************\n");
    printf("CHAR\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu byte\n", sizeof(char));
    printf("min\t%d\n", CHAR_MIN);
    printf("max\t%d\n", CHAR_MAX);
    printf("umax\t%d\n", UCHAR_MAX);

    printf("**********************************\n");
    printf("*               2                *\n");
    printf("**********************************\n");
    printf("SHORT\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(short));
    printf("min\t%d\n", SHRT_MIN);
    printf("max\t%d\n", SHRT_MAX);
    printf("umax\t%d\n", USHRT_MAX);
    printf("----------------------------------\n");
    printf("INT\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(int));
    printf("min\t%d\n", INT_MIN);
    printf("max\t%d\n", INT_MAX);
    printf("umax\t%u\n", UINT_MAX);
    printf("----------------------------------\n");
    printf("LONG\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(long));
    printf("min\t%ld\n", LONG_MIN);
    printf("max\t%ld\n", LONG_MAX);
    printf("umax\t%lu\n", ULONG_MAX);
    printf("----------------------------------\n");
    printf("LONG LONG\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(long long));
    printf("min\t%lld\n", LLONG_MIN);
    printf("max\t%lld\n", LLONG_MAX);
    printf("umax\t%llu\n", ULLONG_MAX);

    printf("**********************************\n");
    printf("*               3                *\n");
    printf("**********************************\n");
    printf("FLOAT\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(float));
    printf("min\t%e\n", FLT_MIN);
    printf("max\t%e\n", FLT_MAX);
    printf("----------------------------------\n");
    printf("DOUBLE\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(double));
    printf("min\t%e\n", DBL_MIN);
    printf("max\t%e\n", DBL_MAX);
    printf("----------------------------------\n");
    printf("LONG DOUBLE\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(long double));
    printf("min\t%Le\n", LDBL_MIN);
    printf("max\t%Le\n", LDBL_MAX);

    printf("**********************************\n");
    printf("*               4                *\n");
    printf("**********************************\n");
    enum color { RED, GREEN, BLUE, YELLOW, WHITE, BLACK };
    printf("ENUM\n");
    printf("----------------------------------\n");
    printf("sizeof\t%lu bytes\n", sizeof(enum color));

    return(0);
}
