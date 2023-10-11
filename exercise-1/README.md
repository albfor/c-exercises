# Exercise 1 

1) Make the Hello World program.

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");

    return 0;
}
```
 
2) Comment your program using the doxygen format.

```c
/**
 * @file hello.c
 * @brief hello world
 * @author Albin Forsberg
 * @version 0.1
 * @date 2023-10-09
 */
#include <stdio.h>

/// This program prints Hello, World! to the console
int main(void)
{
    printf("Hello, World!\n"); // This comment is ignored by doxygen

    return 0;
}

```
 
3) Compile your program in a terminal.

```shell
gcc hello.c -o hello

```
 
3) Run your program.

```shell
./hello

```
