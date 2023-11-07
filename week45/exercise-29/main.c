#include <stdio.h>
#include <stdbool.h>

void primes_in_range(unsigned int n, unsigned int m);
bool isprime(unsigned int n);

int main(void)
{
    primes_in_range(25, 50);

    return 0;
}

/**
 * prints all primes in the range @n..@m
 */
void primes_in_range(unsigned int n, unsigned int m)
{
    for (int i = n; i < m; i++) {
        if (isprime(i)) {
            printf("%d is prime.\n", i);
        }
    }
}

/**
 * returns true if @n is prime
 */
bool isprime(unsigned int n)
{
    if (n == 2) 
        return true;
    if (n % 2 == 0)
        return false;

    int highest_candidate = n / 3;
    for (int i = 3; i <= highest_candidate; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

