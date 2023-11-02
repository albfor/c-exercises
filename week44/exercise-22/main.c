#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100 // maximum string length

int main(void)
{
    char string[MAX_LENGTH];
    printf("enter a string: ");
    fgets(string, sizeof(string), stdin);   // prompt user for a string
    int len = strlen(string);               // number of characters the user put in
    char *end_of_string = string + len;     // address of the end of the string

    printf("With flipped cases: ");

    /**
     *  for each char address between string and end_of_string 
     *      if char found at the char address is upper case
     *          print lower case char
     *      else 
     *          print upper case char
     */
    for (char *ptr = string; ptr < end_of_string; ptr++) {
        if (isupper(*ptr))
            putchar(tolower(*ptr));
        else
            putchar(toupper(*ptr));
    }

    return 0;
}
