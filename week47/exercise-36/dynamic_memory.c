#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct person_t {
    char *name;
    uint8_t age;
} person_t;

int main(void)
{
    int len;
    printf("Enter array length: ");
    scanf("%d", &len);

    person_t *persons = malloc(len * sizeof(person_t *));
   
    printf("sizeof persons: %lu", len * sizeof(person_t *));


    return 0;
}
