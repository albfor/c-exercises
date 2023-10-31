#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *line;
    size_t size;

    printf("The input string: ");
    getline(&line, &size, stdin);
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
