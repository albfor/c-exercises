# Exercise 3

In a shell script file build the program in preprocessors.zip. 
You need to define BUFSIZE=10 when you compile the program.

create build.sh with following script

```shell
gcc main.c lib/mylib.c -I./lib -DBUFSIZE=10 -o main
```

We should then be able to run the following to compile the code.

```shell
sh build.sh
```

