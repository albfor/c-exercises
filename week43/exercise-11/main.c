#include <stdio.h>
#include <ctype.h>

int main(void)
{
    printf("Enter your full name: ");
    char curr = getchar();  // current character
    char prev = ' ';        // previous character, set to space for caps to work

    /**
     * while current character is not a new line
     *  if curr is a letter 
     *      if prev was a space
     *          convert curr to uppercase 
     *      print curr
     *      set prev to curr
     *  else if curr is space and prev wasn't space
     *      print space
     *      set prev to curr
     *  set curr to lowercase from inputbuffer
     */
    while (curr != '\n') {
        if (isalpha(curr)) {
            if (isspace(prev)) {
                curr = toupper(curr);
            }
            putchar(curr);
            prev = curr;
        } else if (isspace(curr) && !isspace(prev)) {
            putchar(curr);
            prev = curr;
        }
        curr = tolower(getchar());

    }

    return 0;
}

