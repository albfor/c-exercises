#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char ch;
    int a, b;

    printf("Enter a lowercase letter: ");
    scanf("%c", &ch);
    if (ch < 'a' || ch > 'z') { // end the program if ch is not a lowercase letter
        printf("ch is not a lowercase letter\n");
        return 1; 
    }
    /*
     * (int)[a..z] -> [97..122]
     * [97..122] - 'a' (97) -> [0..26]
     * [0..26] + 'A' (65) -> [65..90]
     * (char)[65..90] -> [A-Z]
     */
    printf("%c\n", ch - 'a' + 'A');

    srand(time(NULL)); //select a seed for the random number generation
    a = rand(); //generate first number
    b = rand(); //generate second number
    printf("Random ints: %d, %d", a, b);

    return 0;
}
