# Exercise 8

Evaluate the following program. What is the output of the program?

```c
#include <stdio.h>
#include <stdint.h>

#define EXPRESSION (3 * j / k - 2)
#define SET_VARIABLES   \
    {                   \
        i = 3;          \
        j = 2;          \
        k = 0;          \
    }

int main(void)
{
    int i = 0, j = 7, k = 6;
    char a = 'A', b = '3';
    int32_t x, y = 3;
    uint32_t z = 32;
    double d;

    x = EXPRESSION;
    printf("A) %d\n", x);
    
    y -= ((j << 1) & (k >> 1));
    printf("B) %d\n", y);

    x = (!(i && k) || !k) ? k + b : j + b;
    printf("C) %d\n", x);
    
    a += (b + k--) % 10;
    printf("D) %d\n", a);

    d = (double)j * 100 / --k / 3;
    printf("E) %d\n", d);

    x = -1;
    y = (x < z) ? (k < j < 0) : (b >= a < i);
    printf("F) %d\n", y);

    d = x / z;
    printf("G) %f\n", d);

    i = 4;
    j = -1;
    k = 0;

    x = i && j && k;
    y = i || j && k;
    printf("H) %d, %d\n", x, y);

    SET_VARIABLES;
    y = ++i || ++j && k++;
    printf("J) %d, %d, %d, %d\n", i, j, k, y);

    SET_VARIABLES;
    y = ++i && ++j && k++;
    printf("L) %d, %d, %d, %d\n", i, j, k, y);

    i = 4;
    j = --i;
    k = i--;
    printf("M) %d, %d, %d\n", i, j, k);

    i = -1;
    j = 1;

    i && printf("N) Hello World!\n") && --j;

    ++i && j && printf("O) Hello World!\n");

    i || printf("P) Hello World!\n") || j++;

    j-- || !printf("Q) Hello World!\n") || i++;

    printf("R) %d, %d\n", i, j);
}
```

Lets start of by breaking it down into digestible chunks.

**A)**

```c
x = EXPRESSION;
printf("A) %d\n", x);
```

Replace EXPRESSION with the expression:

```c
x = (3 * j / k - 2);
printf("A) %d\n", x);
```

And the variables with their values:


```c
x = (3 * 7 / 6 - 2);
printf("A) %d\n", x);
```

And from here simple maths gives us `x = 1`
after rounding down to closest integer.
As such `printf("A) %d\n", x);` should print `A) 1`
to the terminal.

**B)**

```c
y -= ((j << 1) & (k >> 1));
printf("B) %d\n", y);
```

Let's begin by evaulating the bit shifts.
```math
j << 1
```
replace `j` with its value
```
7 << 1
```
convert to binary
```
0111 << 1 = 1110
```
So to sum up 
```
(j << 1) = 1110
```

And now the same thing for the second bit shift gives us

```
0110 >> 1 = 0011
(k >> 1) = 0011
```

If we now substitute the bit shifts with our binaries we get:
```
y -= 1110 & 0011
```
Which we can easily see equates to 
```
y -= 0010
```
or 
```
y -= 2
```
So we have to subract 2 from the current value of y. And as such we end up with
`y = 1`.

Thus, `printf("B) %d\n", y);` prints `B) 1` to the terminal.

**C)**

```c
x = (!(i && k) || !k) ? k + b : j + b;
printf("C) %d\n", x);
```

Let's begin with the inner most ().

```
i && k
```

Since `i = 0` This expression is going to result false a.k.a. 0. placing it
back into the original expression we get 
```
x = (!(0) || !k) ? k + b : j + b;
```

`!(0)` results in 1. Since we already have a 1 and we are using the logical or
operator we already know the operation is true. Thus: 

```
x = k + b
```

replace variables with values 

```
x = 6 + '3'
```

The ascii value of `'3'` is `51`. As such:
```
x = 57
```

And `printf("C) %d\n", x);` results in the output `C) 57`

**D)**

```c
a += (b + k--) % 10;
printf("D) %d\n", a);
```

From previous examples we know `b = 51`. `k--` does decrement k by one, but it
does not take effect until the next use of `k`. So the value is still 6 here.
Simple modular arithmetics gives us `57 % 10 = 7`. The ascii value of `'A'` is
65. As such 

```c
a += 7;
a = 65 + 7;
a = 72;
```

Thus, `printf("D) %d\n", a);` gives us the output `D) 72`

**E)**

```c
d = (double)j * 100 / --k / 3;
printf("E) %f\n", d);
```

The --k in combination with k-- from D) brings k down by a total of 2. So by
simply replacing the variables with the values we get: 

```
d = (double)7 * 100 / 4 / 3;
```

And then simple arithmetics 

```
d = 58.333333...
```

Because we cast to a double we do not round down to closest integer. Floats
default to rounding to 6 decimals when printing. As such we get the output 
`E) 58.333333`. **Side note**: Something like `0.66666666` will round to 
`0.666667` not `0.6666666` in these situations.

**F)**

```c
x = -1;
y = (x < z) ? (k < j < 0) : (b >= a < i);
printf("F) %d\n", y);
```

`x < z` implicitly casts `x` to an `uint32_t`. As such `-1` turns into `2^32-1`
and cannot possibly be smaller than `z`. So we can now convert the original
expression to the following: 

```c
y = (b >= a < i);
```

Since `b` (51) is smaller than `a` (72) and 0 is not smaller than `i` (0) `y`
is assigned the value 0. Thus, we end up with the output `F) 0`

**G)**

```c
d = x / z;
printf("G) %f\n", d);
```

As in the previous expression `x / z` will implicitly cast `x` to uint32_t.
So `x / z` results in `(2^32 - 1) / 32` which is equal to 134217727 after 
rounding down to the closest integer. Then we store the integer as a double and
print with a %f specifier. Thus, we get the output `G) 134217727.000000`

**H)**

```c
i = 4;
j = -1;
k = 0;
x = i && j && k;
y = i || j && k;
printf("H) %d, %d\n", x, y);
```

Because of `.. && k` we know `x` is going to be 0 without really needing to
calculate it. As for y; && has precedence over ||. Therefore we can rewrite 
`i || j && k` as `i || (j && k)`. Since `i` is true `y` is assigned 1. Thus, we
get the output `H) 0, 1`

**I)**

```c
x = i && j || k;
y = i || j || k;
printf("I) %d, %d\n", x, y);
```

Because of previously mentioned precedence we can rewrite `x` as `(i && j) || k`.
replacing variables with values gives `(4 && -1) || 0` -> `1 || 0` -> 1. Since
we know `i` is true `y` is going to be true. Thus, we get the output `I) 1, 1`

**J)**

```c
SET_VARIABLES;
y = ++i || ++j && k++;
printf("J) %d, %d, %d, %d\n", i, j, k, y);
```

`SET_VARIABLES` sets `i` to 3 `j` to 2 and `k` to 0. `y = ++i || ++j && k++` ->
`y = ++i || (++j && k++)` -> `4 || (++j && k++)` Since 4 is true assign `y` 1.
`++j && k++` is never evaluated and therefore their values remain the same.
Thus we get the output `J) 4, 2, 0, 1`.

**K)**

```c
SET_VARIABLES;
y = (123 && --i) ? k++ : ++k;
printf("K) %d, %d, %d, %d\n", i, j, k, y);
```

We start of by setting the variables i, j & k again. Then we evaluate the
expression `123 && --i` since 123 is true we have to evaluate `--i`. `true && 2`
is `true`. Which leads to `y = k++`. This assigns `k` to `y` and then increases
`k`. Meaning `y` is 0, `i` is 2, `j` is 2 and `k` is 1. Thus, we have the output
`K) 2, 2, 1, 0`.

**L)**

```c
SET_VARIABLES;
y = ++i && ++j && k++;
printf("L) %d, %d, %d, %d", i, j, k, y);
```

We start of by setting the variables i, j & k again. && operations should be
evaluated from left to right. Since `i` and `j` are greater than 0 everything in
the expression will be evaluated, but `k` will not increment until after the 
expression. Resulting in `y` being assigned 0. Thus, we get the output
`L) 4, 3, 1, 0`

**M)**

```c
i = 4;
j = --i;
k = i--;
printf("M) %d, %d, %d\n", i, j, k);
```

The `j` expression decrements `i` before assigning it to `y`. The `k` expression does it
after assigning `i` to `k`. Giving us the outputs `M) 2, 3, 3`.

**N)**

```c
i = -1;
j = 1;

i && printf("N) Hello World!\n") && --j;
```

Since `i` is not eqaul to 0 we have to evaluate the next expression. `printf()`
returns the number of characters printed, which in this case is 16. This also
prints `N) Hello World!` to the terminal before it proceeds to decrement j.


**O)**

```c
++i && j && printf("O) Hello World!\n");
```

This increments `i` giving us 0 and as such nothing else is evaluated in the
expression and nothing is printed.

**P)**

```c
i || printf("P) Hello World!\n") || j++;
```

Since `i` is false we have to evaluate the next part which prints 
`P) Hello World!` and evaluates to true. Thus, we are not incrementing j.

**Q)**

```c
j-- || !printf("Q) Hello World!\n") || i++;
```

We start off by evaluating `j` before decrementing it. Since it is 0 we have to
continue evaluating the expression. `!printf()` with a not empty string should
evaluate to 0 and print the string to the terminal, in this case 
`Q) Hello World!`. And finally, it will increment i.

**R)**

```c
printf("R) %d, %d\n", i, j);
```

Simply going to print `R) 1, -1`
