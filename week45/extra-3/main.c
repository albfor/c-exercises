#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main(void)
{
    int (*adder)(int a, int b) = add;
    int (*suber)(int a, int b) = sub;
    int (*muler)(int a, int b) = mul;
    int (*diver)(int a, int b) = div;
    printf("%d\n", adder(5, 7));
    printf("%d\n", suber(5, 7));
    printf("%d\n", muler(5, 7));
    printf("%d\n", diver(5, 7));

    return 0;
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}





