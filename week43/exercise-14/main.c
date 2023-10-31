#include <stdio.h>
#include <stdbool.h>

int read_input() {
    int number;
    char term;
    printf("Enter positive integer [2..10000]: ");
    while (scanf("%u%c", &number, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
    }

    if (number < 2 || number > 10000) {
        printf("Positive integer [2..10000]\n");
        return read_input();
    }
    return number;
}

int main(void)
{
    bool isprime = true;
    int number = read_input();
    if (number % 2 == 0 && number != 2) {
            printf("divisible by %d\n", 2);
            isprime = false;
    }
    int gpd = number / 3; // greatest possible denominator not spotted by % 2
    for (int i = 3; i < gpd; i += 2) {
        if (number % i == 0) {
            printf("divisible by %d\n", i);
            isprime = false;
            break;
        }
    }

    if (isprime)
        printf("%d is a prime\n", number);
    else 
        printf("%d is not a prime\n", number);


    return 0;
}
