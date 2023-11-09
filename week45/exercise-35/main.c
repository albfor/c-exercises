#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isprime(unsigned int n);

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

/**
 * returns true if @n is prime
 */
bool isprime(unsigned int n)
{
    if (n == 2) 
        return true;
    if (n % 2 == 0 || n < 2)
        return false;

    int highest_candidate = n / 3;
    for (int i = 3; i <= highest_candidate; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}
