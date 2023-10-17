#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    char ch;
    int a, b;

    printf("Enter a lowercase letter: ");
    scanf("%c", &ch);
    if (ch < 'a' || ch > 'z') {
        printf("ch is not a lowercase letter\n");
        return 1; // end the program if ch is not a lowercase letter
    }
    printf("%c\n", ch - 'a' + 'A');

    srand(time(NULL));
    a = rand();
    b = rand();
    printf("Random ints: %d, %d", a, b);

    return 0;
}
