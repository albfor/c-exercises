#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100


int main(void)
{
    int guess, res;
    char term;

    srand(time(NULL));
    int secret_number = rand() % MAX;
    printf("%d\n", secret_number);
    
    printf("Enter an integer between 0 and %d: ", MAX);
    while (!scanf("%d%c", &guess, &term)) {
        while (getchar() != '\n'); // throw away the garbage input scanf failed to process.
        printf("You are a dissapointment to your family.\n");
        printf("Please, try entering an integer again...\n");
    }

    if (guess == secret_number)
        printf("Good boy!\n");
    else 
        printf("You tried.\n");

    return 0;
}
