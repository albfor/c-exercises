#include "linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

typedef struct node
{
    int data;
    struct node *next;
} node_t;

struct list 
{
    node_t *head;
    size_t size;
};

list_t *list_create()
{
    list_t *list;
    list = malloc(sizeof(list_t));
    list->size = 0;
    list->head = NULL;
    return list;
}

bool list_insert(list_t *list, int data) {
    if (list == NULL) // make sure list exist
        return false;
    node_t *new = (node_t*) malloc(sizeof(node_t));
    if (new == NULL) // make sure memory was allocated
        return false;

    list->size++;
    new->next = NULL;
    new->data = data;

    if (list->head == NULL) {
        list->head = new;
    } else {
        node_t *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }

    return true;
}

bool list_update(list_t *list, int old_data, int new_data) {
    if (list == NULL || list->size == 0)
        return false;

    node_t *current = list->head;
    while (current != NULL) {
        if (current->data == old_data) {
            current->data = new_data;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool list_remove(list_t *list, int data) {
    if (list == NULL || list->head == NULL)
        return false;

    node_t *current = list->head;
    if (current->data == data) {
        list->head = current->next;
        free(current);
        return true;
    } else {
        while (current->next != NULL) {
            if (current->next->data == data) {
                node_t *to_be_removed = current->next;
                current->next = current->next->next;
                free(to_be_removed);
                list->size--;
                break;
            }
            current = current->next;
        }
    }

    return true;
}

int list_find(list_t *list, int data) {
    if (list == NULL || list->head == NULL)
        return NOT_FOUND;

    node_t *current = list->head;
    int index = 0;
    while (current != NULL && current->data != data) {
        index++;
        current = current->next;
    }
    return current->data == data ? index : NOT_FOUND;
}

int list_get(list_t *list, int index) {
    if (list == NULL || index >= list->size)
        exit(1);
    node_t *current = list->head;
    int current_index = 0;
    while (current_index < index) {
        current = current->next;
        current_index++;
    }
    return current->data;
}

int list_size(list_t *list) {
    if (list == NULL)
        return NOT_FOUND;
    return list->size;
}

bool list_destroy(list_t *list) {
    if (list == NULL)
        return false;
    node_t *current = list->head;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
    return true;
}
