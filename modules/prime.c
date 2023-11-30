#include <stdbool.h>
#include "prime.h"

/**
 * returns true if @n is prime
 */
bool isprime(unsigned int number)
{
    if (number == 2) 
        return true;
    if (number % 2 == 0 || number < 2)
        return false;

    int highest_candidate = number / 3;
    for (int i = 3; i <= highest_candidate; i += 2) {
        if (number % i == 0)
            return false;
    }

    return true;
}
