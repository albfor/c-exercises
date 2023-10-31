#include <stdio.h>
#include <string.h>

int main(void)
{
    // init
    char string[255];           // arbitrarily selected string size
    scanf("%s", string);        // read string
    int len = strlen(string);   // get length of string

    // print the string in reverse order
    for (int i = 0; i < len; i++) {
        printf("%c", string[len - (1 + i)]);
    }
    printf("\n");

    return 0;
}

