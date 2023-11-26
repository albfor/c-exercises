#include "strspl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *string;
static char *curr;
static char *next;

char *split_string(const char *str, const char delim) {
    if (str != NULL) {
        int i = 0;
        while (str[i] == delim) { i++; }
        string = curr = (char *)malloc(strlen(str) - i);
        strcpy(string, str + i);
        return get_next_token(delim);
    }
    if (next == NULL) {
        free(string);
        return NULL;
    }
    curr = next;
    return get_next_token(delim);
}

char *get_next_token(const char delim) {
    if (find_next_delim(curr, delim) == -1)
        next = NULL;
    else
        next = curr + find_next_delim(curr, delim) + 1;
    curr[find_next_delim(curr, delim)] = 0;
    return curr;
}

int find_next_delim(const char *str, const char delim) {
    int counter = 0;
    while (str[counter] != delim && str[counter] != 0) { counter++; }
    return str[counter] == 0 ? -1 : counter;
}
