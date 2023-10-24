/**
 * @file main.c
 * @date 2023-10-19
 * @author Albin Forsberg
 * @brief Let a player guess a random number in the range of 0..99. The player
 * has a maximum of 10 attempts to guess the number. After each game the player
 * is offered to play again.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define ATTEMPTS 10

void make_guess(unsigned short *guess);
bool check_guess(unsigned short guess, unsigned short secret, unsigned short attempt);

int main(void)
{
    unsigned short guess;
    char play_again = 'y';
    srand(time(NULL)); // Seed random number generation.
    
    while (play_again == 'y' || play_again == 'Y') {
        unsigned short secret_number = rand() % MAX; // Pick a random number.
        for (unsigned short attempt = 0; attempt < ATTEMPTS; attempt++) {
            make_guess(&guess);
            if (check_guess(guess, secret_number, attempt))
                break;
        }

        printf("Play again? (y/n)");
        scanf("%c", &play_again);
    }

    return 0;
}

/**
 * @brief Reads the players guess and validates it.
 * @param *guess address of where to store the guess.
 */
void make_guess(unsigned short *guess) {
    char term;
    printf("Enter guess [0..%d]: ", MAX - 1);
    while (scanf("%hu%c", guess, &term) != 2 || term != '\n') {
        while (getchar() != '\n'); // Throw away the garbage input scanf failed to process.
        printf("You are a dissapointment to your family.\n");
        printf("Please, try again...\n\n");
        printf("Enter guess [0..%d]: ", MAX - 1);
    }

    if (*guess >= MAX) {
        printf("It's not that hard to pick a number in the range 0..%d\n", MAX - 1);
        make_guess(guess);
    }
}

/**
 * @brief Check if player managed to guess the secret number.
 * Also prints hints.
 * @param guess The players guess.
 * @param secret The secret number the player is trying to guess.
 * @param attempt Count of attempts made.
 * @return true if player guessed sercret, otherwise false.
 */
bool check_guess(unsigned short guess, unsigned short secret, unsigned short attempt) {
    if (guess == secret) {
        printf("Good boy!\n");
        return true;
    }
    else if (attempt == ATTEMPTS - 1) {
        printf("Get wrecked kiddo.\n");
        printf("The secret number was %d.\n", secret);
    }
    else if (guess < secret)
        printf("Too low.\n");
    else 
        printf("Too high.\n");
    return false;
}

