#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define LENGTH 100

int main(void)
{
    char line[LENGTH]; 
    
    printf("The input string: ");
    fgets(line, LENGTH, stdin);
    printf("The output string:\n");
    int len = strlen(line);             // length of input
    for (int i = 0; i < len; i++) {
        if (isspace(line[i]))
            putchar('\n');
        else
            putchar(line[i]);
    }

    return 0;
}
