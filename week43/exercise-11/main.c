#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    bool upper = true;
    printf("Enter your full name: ");
    char c = getchar();
    char prev = c;
    while (c != '\n') {
        if (isalpha(c)) {
            if (upper) {
                c = toupper(c);
                upper = false;
            }
            putchar(c);
        } else if (isspace(c) && !isspace(prev)) {
            upper = true;
            putchar(c);
        }
        prev = c;
        c = tolower(getchar());

    }

    return 0;
}

