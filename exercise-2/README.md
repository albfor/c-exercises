# Exercise 2

Make a program to print your full name to the terminal.

```c
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

```

Your full name shall be defined as a macro in the command line when you compile your program.

```shell
gcc name.c -DNAME='"Ditt Namn"' -o name
```

If you try to compile without `-DNAME='"namn"'` you should get an error "NAME not defined".
```shell
gcc name.c -o name
```
