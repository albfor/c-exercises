#include <stdio.h>
#include <stdint.h>

#define MAX 255

uint8_t read_input();

int main(void)
{
    uint8_t input = read_input();

    // print binary representation of the input.
    for (int i = 7; i >= 0; i--) {
        printf("%d", (input & (1 << i)) > 0);
    }

    return 0;
}

/**
 * Read an integer between 0 and 255 from stdin.
 */
uint8_t read_input() {
    int number;
    char term;
    printf("Enter integer [0..%d]: ", MAX);
    while (scanf("%u%c", &number, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
        printf("Please, try again...\n\n");
        printf("Enter integer [0..%d]: ", MAX);
    }

    if (number > MAX || number < 0) {
        printf("It's not that hard to pick a number in the range 0..%d\n", MAX);
        return read_input(); // if we fail to pick a suitable number start over.
    }
    return number;
}

