#include <stdio.h>

int main(void)
{
    #ifndef NAME
    #error "NAME not defined"
    #else 
        printf("%s\n", NAME);
    #endif /* ifndef NAME */

    return 0;
}
