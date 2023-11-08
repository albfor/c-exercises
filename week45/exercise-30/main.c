#include <stdio.h>

void say_value(int a)
{
    printf("Value of a is %d\n", a);
}

// 3. function adding 5 to value at given address
void add5(int *ptr)
{
    *ptr += 5;
}

int main(void)
{
    // 1. create values and pointers 
    int a = 5;
    char b = 's';
    int *ptra = &a;
    char *ptrb = &b;

    // 2. change values via the pointers
    *ptra = 6;
    *ptrb = 'b';

    // 3. calling add5
    add5(&a);
    
    // 4. function pointer
    void (*funcptr)(int a) = say_value;
    // calling it
    funcptr(a);

    return 0;
}
