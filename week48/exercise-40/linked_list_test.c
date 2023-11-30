#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

/**
 * Simple test of my linked list.
 */
int main(void)
{
    list_t *list = list_create();
    assert(list != NULL);
    list_print(list);
    printf("List creation successful.\n\n");
    list_insert(list, 1);
    list_insert(list, 2);
    list_insert(list, 3);
    list_insert(list, 2);
    list_print(list);
    assert(list_size(list) == 4);
    printf("List insertion successful.\n\n");
    list_update(list, 2, 4);
    list_print(list);
    assert(list_get(list, 1) == 4);
    assert(list_get(list, 3) == 2);
    printf("List update successful.\n\n");
    assert(list_find(list, 3) == 2);
    printf("List find successful.\n\n");
    list_remove(list, 1);
    list_print(list);
    printf("size: %d.\n\n", list_size(list));
    assert(list_size(list) == 3);
    printf("List remove successful.\n\n");
    list_destroy(list);
    printf("List destroyed.\n\n");
    return 0;
}
