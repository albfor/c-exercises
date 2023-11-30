# Exercise 40

Implement a multiple-instance linked list module of unique and sorted data 
elements of type int. The module shall be tested using assertion and support 
the following operations:

1. Creating a list
2. Inserting a new node in a list
3. Change a data element in a list
4. Deleting a value from a list
5. Searching for a value in a list
6. Getting data stored in the nth node of a list
7. Getting available number of elements stored in a list
8. Destroying a list

Sorted means that when you want to add a new data element, you should find the 
right position for the node in a way that the list is always sorted.

## Compilation

If you have make installed simply run 

```shell
make
```

Else
```shell
gcc -o test linked_list_test.c linked_list.c && ./test
```

