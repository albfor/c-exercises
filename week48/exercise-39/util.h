#ifndef UTIL_H
#define UTIL_H

#include <string.h>

/// Greatest common divisor of a and b.
///
/// Calculate the greatest common divisor of two unsinged integers.
///     Example: gcd(8, 12) -> 4.
///
/// @param a An integer.
/// @param b An integer.
/// @return Returns the largest divisor of both a & b.
unsigned int gcd(unsigned int a, unsigned int b);

/// Least common multiple.
///
/// Get the least common multiple of two unsinged integers.
///     Example: lcm(4, 6) -> 12.
///
/// @param a An integer.
/// @param b An integer.
/// @return Returns the least common divisor of a & b.
unsigned int lcm(unsigned int a, unsigned int b);

/// Sort a string in alphabetical order.
///
/// Sort a string in alphabetical order, with the suborder uppercase to lower case.
/// The sorting is done in place.
///
/// @param char * str Character pointer to the beginning of the string to sort.
/// @return void
void sort_string(char * str);

#endif
