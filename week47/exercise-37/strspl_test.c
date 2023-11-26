#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strspl.h"

int tests_run = 0;

#define RED             "\x1b[31m"
#define GREEN           "\x1b[32m"
#define COLOR_RESET     "\x1b[0m"

#define FAIL() printf(RED "\nFAILURE" COLOR_RESET " in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while (0)
#define _verify(test) do { int r = test(); tests_run++; if (r) all_failed += r; } while(0)

int basic_test() {
    char delim = ' ';
    char str[] = "This is a string.";
    char *res = split_string(str, delim);
    _assert(!strcmp(res, "This"));
    res = split_string(NULL, delim);
    _assert(!strcmp(res, "is"));
    res = split_string(NULL, delim);
    _assert(!strcmp(res, "a"));
    res = split_string(NULL, delim);
    _assert(!strcmp(res, "string."));
    res = split_string(NULL, delim);
    _assert(res == NULL);
    return 0;
}

int prefix_delims() {
    char str[] = "  This";
    char *res = split_string(str, ' ');
    _assert(strcmp("This", res) == 0);
    return 0;
}

int find_delims_test() {
    char str[] = "This is a string.";
    _assert(4 == find_next_delim(str, ' '));
    _assert(-1 == find_next_delim(str, ','));
    return 0;
}

int all_tests() {
    int all_failed = 0;
    _verify(basic_test);
    _verify(prefix_delims);
    _verify(find_delims_test);
    return all_failed;
}

int main(void)
{
    printf("Running tests...");
    int result = all_tests();
    if (result == 0)
        printf(GREEN "PASSED" COLOR_RESET "\n");
    printf("\nTests done: %d/%d\n", tests_run - result, tests_run);

    return 0;
}
