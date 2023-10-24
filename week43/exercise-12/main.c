#include <stdio.h>

int read_input();

int main(void)
{
    int sum = 0; 
    int number = read_input();
    // sum all even numbers smaller than @number
    for (int i = 0; i < number; i += 2) {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}

int read_input() {
    int input;
    char term;
    printf("Enter positive integer: ");
    while (scanf("%d%c", &input, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
    }

    if (input < 0) {
        printf("Positive integer\n");
        return read_input();
    }
    return input;
}
