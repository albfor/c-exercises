#include <stdio.h>
#include <stdint.h>

int read_input();

int main(void)
{
    int sum = 0, a = read_input();
    for (int i = 0; i < a; i += 2) {
        sum += i;
    }
    printf("%d\n", sum);
    return 0;
}

int read_input() {
    int a;
    char term;
    printf("Enter positive integer: ");
    while (scanf("%u%c", &a, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
    }

    if (a < 0) {
        printf("Positive integer\n");
        return read_input();
    }
    return a;
}
