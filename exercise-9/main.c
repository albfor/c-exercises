#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define ATTEMPTS 10


int main(void)
{
    int guess;
    char term;

    srand(time(NULL));
    int secret_number = rand() % MAX;
    printf("%d\n", secret_number); // TODO: remove this line before release :^)
    
    for (int i = 0; i < ATTEMPTS; i++) {
        printf("Enter an integer between 0 and %d: ", MAX);
        while (!scanf("%d%c", &guess, &term)) {
            while (getchar() != '\n'); // throw away the garbage input scanf failed to process.
            printf("You are a dissapointment to your family.\n");
            printf("Please, try entering an integer again...\n");
        }

        if (guess == secret_number) {
            printf("Good boy!\n");
            break;
        }
        else if (i == ATTEMPTS - 1)
            printf("Get wrecked kiddo.\n");
        else if (guess < secret_number)
            printf("Too low.\n");
        else 
            printf("Too high.\n");

    }

    return 0;
}