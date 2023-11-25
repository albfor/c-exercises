#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LEN 128

typedef struct person_t {
    char *name;
    uint8_t age;
} person_t;

person_t *createPersonArray(size_t size) {
    person_t *people = (person_t *) malloc(sizeof(person_t) * size);
    if (people == NULL) {
        fprintf(stderr, "Could not allocate memory for people\n");
        exit(EXIT_FAILURE);
    }
    return people;
}

void fillPersonArray(person_t *people, size_t size) {
    for (int i = 0; i < size; i++) {
        char name[NAME_MAX_LEN];
        printf("enter [name age]: ");
        scanf("%s %hhd", name, &people[i].age);
        people[i].name = (char *) malloc(strlen(name));

        if (people[i].name == NULL) {
            fprintf(stderr, "Could not allocate memory for name, people[%d]\n", i);
            exit(EXIT_FAILURE);
        }

        strcpy(people[i].name, name);
    }
}

void printPersonArray(person_t *people, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("name: %s, age: %d\n", people[i].name, people[i].age);
    }
}

void freePersonArray(person_t *people, size_t size) {
    for (int i = 0; i < size; i++) {
        free(people[i].name);
    }
    free(people);
}

int main(void)
{
    int size;
    printf("Enter number of people: ");
    scanf("%d", &size);
    person_t *people = createPersonArray(size);
    fillPersonArray(people, size);
    printPersonArray(people, size);
    freePersonArray(people, size);

    return EXIT_SUCCESS;
}
