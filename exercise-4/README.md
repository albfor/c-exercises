# Exercise 3

Make a program to print a macro(NUMBER) whose value is an integer to the terminal.

If NUMBER has not been defined, an error message shall be generated and compilation shall be terminated.

If NUMBER is not equal to 8 or 16,  an error message shall be generated and compilation shall be terminated.

The macro shall be defined when you compile the program.


This should print 8
```shell
gcc macro.c -DNUMBER=8 -o macro && ./macro
```

This should print 16
```shell
gcc macro.c -DNUMBER=16 -o macro && ./macro
```

This should break with the error "NUMBER not defined"
```shell
gcc macro.c -o macro && ./macro
```

This should break with the error "NUMBER is neither 8 nor 16"
```shell
gcc macro.c -DNUMBER -o macro && ./macro
```

