/**
 * Technically accurate, but practically useless solution.
 */
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

bool read_date();
bool read_digits(int digits);
bool read_char(char ch);

int main(void)
{
    printf("Enter date (YYYY-MM-DD HH:mm:ss): ");
    if (read_date())
        printf("Aye!\n");
    else 
        printf("Boo!\n");

    return 0;
}

/**
 * Makes sure input is: dddd-dd-dd dd:dd:dd
 * where d is replaced with a digit
 */
bool read_date() {
    // read year
    if (!read_digits(4))
        return false;
    if (!read_char('-'))
        return false;
    // read month
    if (!read_digits(2))
        return false;
    if (!read_char('-'))
        return false;
    // read day
    if (!read_digits(2))
        return false;
    if (!isspace(getchar()))
        return false;
    // read hour
    if (!read_digits(2))
        return false;
    if (!read_char(':'))
        return false;
    // read min
    if (!read_digits(2))
        return false;
    if (!read_char(':'))
        return false;
    // read sec
    if (!read_digits(2))
        return false;
    return true;
}

/**
 * Read @digits number of digits
 * return true if read correctly else return false
 */
bool read_digits(int digits) {
    for (int i = 0; i < digits; i++) {
        if (!isdigit(getchar())) {
            return false;
        }
    }
    return true;
}

/**
 * return true if getchar() is @ch else false
 */
bool read_char(char ch) {
    if (getchar() != ch) {
        return false;
    }
    return true;
}

