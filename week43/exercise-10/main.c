#include <stdio.h>
#include <stdint.h>

#define MAX 255

uint8_t read_input();

int main(void)
{
    uint8_t input;
    input = read_input();
    printf("%d\n", input);
    return 0;
}

uint8_t read_input() {
    int a;
    char term;
    printf("Enter integer [0..%d]: ", MAX);
    while (scanf("%u%c", &a, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
        printf("Please, try again...\n\n");
        printf("Enter integer [0..%d]: ", MAX);
    }

    if (a > MAX || a < 0) {
        printf("It's not that hard to pick a number in the range 0..%d\n", MAX);
        return read_input();
    }
    return a;
}

