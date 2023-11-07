#include <stdio.h>

int equals(char str1[], char str2[]);

int main(void)
{
    char str1[] = "mystring";
    char str2[] = "mystring1";
    char str3[] = "cake";

    printf("%s equals %s: %d\n", str1, str2, equals(str1, str2));
    printf("%s equals %s: %d\n", str1, str3, equals(str1, str3));

    return 0;
}

int equals(char str1[], char str2[])
{
    int equals = 1;
    int i = 0;
    while (str1[i] != '\0') {
        if (str1[i] != str2[i]) {
            equals = 0;
            break;
        }
        i++;
    }
    // make sure str2 ends where str1 does
    if (str2[i] != '\0')
        equals = 0;

    return equals;
}

