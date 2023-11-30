#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct list list_t; // linked list

/// @brief Create a linked list.
///
/// Initializes a new linked list and sets its head to NULL and size to 0.
///
/// @return pointer to a new linked list.
list_t *list_create(void);

/// @brief Insert item into list.
///
/// Insert item of type int into the given list.
///
/// @param list the list.
/// @param data the item to insert.
/// @return Returns true if operation was successful.
bool list_insert(list_t *list, int data);

/// @brief Change the value of a node.
///
/// Change the value of the first node where the data equals old_data to 
/// new_data.
///
/// @param list the list.
/// @param old_data the value to change.
/// @param new_data the value to change to.
bool list_update(list_t *list, int old_data, int new_data);

/// @brief Remove value from list.
///
/// Removes the first node where its data equals the parameter data from the
/// linked list.
///
/// @param list A linked list with 1 integer stored in each node.
/// @param data The value of the data we want to remove from the linked list.
/// @return Returns true if deletion was successful.
bool list_remove(list_t *list, int data);

/// @brief Get index of first node with the value data.
/// @param list A linked list.
/// @param data The data to search for.
/// @return Returns the index of data. If data doesn't exist in list return
///         NOT_FOUND.
int list_find(list_t *list, int data);

/// @brief Get value at index.
/// @param list A linked list.
/// @param index The index the value to return.
/// @return Returns the value of node at index.
int list_get(list_t *list, int index);

/// @brief Number of nodes stored in list
///
/// @param list A linked list.
/// @return Returns the size of list. If list doesn't exist return NOT_FOUND.
int list_size(list_t *list);

/// @brief Frees the list and all nodes in the list.
/// @param list A linked list.
/// @return Returns true if deletion was successful, false if list is NULL.
bool list_destroy(list_t *list);

/// @brief print all nodes in the list.
void list_print(list_t *list);
#endif // !LINKED_LIST_H
