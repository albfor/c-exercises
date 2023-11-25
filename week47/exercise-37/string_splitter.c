#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *start;

static char *split_string(const char *str, const char delimiter) {
    if (str != NULL) {
        int len = strlen(str);
        start = (char *) malloc(len);
        strcpy(start, str);
        for (int i = 0; i < len; i++) {
            if (start[i] == '\0') 
                return NULL;
            if (start[i] != delimiter) {
                start += i;
                break;
            }
        }

        int counter = 0;
        while (start[counter] != '\0') {
            if (start[counter] == delimiter) {
                start[counter] = '\0';
                break;
            }
            counter++;
        }

        return start;
    } 

    int counter = 0;
    while (start[counter] != '\0') {
        counter++;
    }
    start += ++counter;
    counter = 0;
    while (start[counter] != '\0') {
        if (start[counter] == delimiter) {
            start[counter] = '\0';
            break;
        }
        counter++;
    }

    return counter == 0 ? NULL : start;
}

int main(void)
{
    char str[] = "     This is a string";
    char *pch = split_string(str, ' ');

    while (NULL != pch) {
        printf("%s\n", pch);
        pch = split_string(NULL, ' ');
    }

    return 0;
}
