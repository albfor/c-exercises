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
    if (read_date()) {
        printf("Aye! Winners gets ice cream.\n");
        printf("\n");
        printf("            .oo.\n");
        printf("          oGGGGGGo\n");
        printf("         GGGGGGGGGG\n");
        printf("  .mMMMMMMGGGGGGEEEE=\n");
        printf(" MMMMMMMMMMMGGEEEEEEEE\n");
        printf("MMMMMMMMMMMNICKEEEEEEEE\n");
        printf("MMMMMMMMMMMMMEEEEEEEEEE\n");
        printf("!MMMMMMMMMMMOOEEEEEEEE\n");
        printf(" MMM!MMMMMMOOOOOOE!=\n");
        printf("  MM!!!!!!!!!!!!!!!\n");
        printf("   MM!!!!!!!!!!!!!'\n");
        printf("   !M!!!!!!!!!!!!!\n");
        printf("    MM!!!!!!!!!!!'\n");
        printf("    MM!!!!!!!!!!!\n");
        printf("    ! `!!!!!!!!!'\n");
        printf("    .  !!!!!!!!!\n");
        printf("       `!!!!!!!'\n");
        printf("        !!!!!!!\n");
        printf("        `!!!!!'\n");
        printf("         !!!!!\n");
        printf("         `!!!'\n");
        printf("          !!!\n");
        printf("          `!'\n");
        printf("           !\n");
    }
    else {
        printf("Boo! Failures get zapped.\n");
        printf("\n");
        printf("o\n");
        printf("\\_/\\o\n");
        printf("( Oo)                    \\|/\n");
        printf("(_=-)  .===O-  ~~Z~A~P~~ -O-\n");
        printf("/   \\_/U'                /|\\\n");
        printf("||  |_/\n");
        printf("\\\\  |\n");
        printf("{K ||\n");
        printf("| PP\n");
        printf("| ||\n");
        printf("(__\\\\\n");
    }

    return 0;
}

/**
 * Makes sure input is: dddd-dd-dd dd:dd:dd
 * where d is replaced with a digit
 */
bool read_date() {
    if (!read_digits(4))        // year
        return false;
    if (!read_char('-'))
        return false;
    if (!read_digits(2))        // month
        return false;
    if (!read_char('-'))
        return false;
    if (!read_digits(2))        // day
        return false;
    if (!isspace(getchar()))
        return false;
    if (!read_digits(2))        // hour
        return false;
    if (!read_char(':'))
        return false;
    if (!read_digits(2))        // minute
        return false;
    if (!read_char(':'))
        return false;
    if (!read_digits(2))        // second
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

