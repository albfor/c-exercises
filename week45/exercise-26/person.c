#include <stdio.h>
#include <stdlib.h>

typedef struct person_t {
    int age;
    float height;
    char name[16];
} person_t;

person_t *create_person();

int main(void)
{
    person_t *person = create_person();
    printf("%d\n%f\n%s\n", person->age, person->height, person->name);

    return 0;
}

person_t *create_person()
{
    person_t *new_person = malloc(sizeof(person_t));
    printf("Enter person (age, height, name): ");
    scanf("%d, %f, %s", &new_person->age, &new_person->height, new_person->name);

    return new_person;
}

