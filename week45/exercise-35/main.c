#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("enter a number you dummy\n");
        return 1;
    }
    printf("%s is ", argv[1]);
    isprime(atoi(argv[1])) ? : printf("not ");
    printf("prime.");

    return 0;
}

