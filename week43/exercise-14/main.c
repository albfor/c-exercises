#include <stdio.h>
#include <stdbool.h>

int read_input() {
    int a;
    char term;
    printf("Enter positive integer [2..10000]: ");
    while (scanf("%u%c", &a, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
    }

    if (a < 2 || a > 10000) {
        printf("Positive integer [2..10000]\n");
        return read_input();
    }
    return a;
}

int main(void)
{
    bool isprime = true;
    int number = read_input();
    for (int i = 2; i < number; i++) {
        if (number % i == 0){
            printf("divisible by %d\n", i);
            isprime = false;
        }
    }

    if (isprime)
        printf("%d is a prime\n", number);
    else 
        printf("%d is not a prime\n", number);


    return 0;
}
