#include "linked_list.h"
#include <assert.h>
#include <stdio.h>

/**
 * Simple test of my linked list.
 */
int main(void)
{
    list_t *list = create_list();
    assert(list != NULL);
    printf("List creation successfull\n");
    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 2);
    assert(size(list) == 4);
    printf("List insertion successfull\n");
    update(list, 2, 4);
    assert(get(list, 1) == 4);
    assert(get(list, 3) == 2);
    printf("List update successfull\n");
    assert(find(list, 3) == 2);
    printf("List find successfull\n");
    destroy(list);
    printf("List destroyed\n");

    return 0;
}
