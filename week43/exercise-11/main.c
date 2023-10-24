#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    bool upper = true;
    printf("Enter your full name: ");
    char c = getchar();
    while (c != '\n') {
        if (isalpha(c)) {
            if (upper) {
                c = toupper(c);
                upper = false;
            }
            putchar(c);
        } else if (isspace(c)) {
            upper = true;
            putchar(c);
        }
        c = tolower(getchar());
    }

    return 0;
}

