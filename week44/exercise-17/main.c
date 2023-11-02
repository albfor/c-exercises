#include <stdio.h>
#include <string.h>

#define LENGTH 255

int main(void)
{
    // init
    char string[LENGTH];                    // arbitrarily selected string size
    fgets(string, sizeof(string), stdin);   // read string
    int len = strlen(string);               // get length of string

    // print the string in reverse order
    for (int i = 0; i < len; i++) {
        putchar(string[len - (1 + i)]);
    }
    printf("\n");

    return 0;
}

