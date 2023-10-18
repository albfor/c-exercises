#include <stdio.h>

int main(void)
{
    /*
     * psuedo code
     * if NUMBER isn't defined
     *      die
     * else if NUMBER is neither 8 nor 16
     *      die
     * else 
     *      print NUMBER
     */

    #ifndef NUMBER
    #error "NUMBER not defined"
    #elif (NUMBER != 8) && (NUMBER != 16)
    #error "NUMBER is neither 8 nor 16"
    #else
        printf("%d\n", NUMBER);
    #endif /* ifndef NUMBER */

    return 0;
}
