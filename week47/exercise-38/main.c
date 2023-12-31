#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_SIZE 8
#define USERS_SIZE 10

const char NAMES[][NAME_SIZE] = {
    "albin", "bob", "charles", "david", "erik", "fredrik", "gustav", "henrik"
};

typedef struct user_t {
    char name[NAME_SIZE];
    uint32_t id;
} user_t;

void fillUsers(user_t *users) {
    int id = 1;
    for (int i = 0; i < USERS_SIZE; i++) {
        strcpy(users[i].name, NAMES[rand() % sizeof(NAMES[0])]);
        users[i].id = id++;
    }
}

void printUsers(user_t *users) {
    for (int i = 0; i < USERS_SIZE; i++) {
        printf("%s:%d\n", users[i].name, users[i].id);
    }
}

void writeUsers(user_t *users) {
    FILE *myfile = fopen("users.dat", "wb");
    if (myfile == NULL) {
        fprintf(stderr, "\ncannot open users.tmp\n");
        exit(1);
    }

    if (fwrite(users, sizeof(user_t), USERS_SIZE, myfile)) {
        printf("Succuessfully wrote users to file\n");
    } else {
        printf("Failed to write users to file\n");
    }
    fclose(myfile);
}

user_t *readUsers() {
    FILE *myfile = fopen("users.dat", "rb");
    if (myfile == NULL) {
        fprintf(stderr, "cannot open file: users.dat");
        exit(1);
    }
    user_t *usersPtr = calloc(USERS_SIZE, sizeof(user_t));
    if (fread(usersPtr, sizeof(user_t), USERS_SIZE, myfile))
        printf("Successfully read users from file\n");
    else 
        printf("Failed to read users\n");
    fclose(myfile);

    return usersPtr;
}

void updateUserName(uint32_t id, char name[8]) {
    FILE *myfile = fopen("users.dat", "rb+");
    user_t *usr;
    uint32_t offset_to_user = (id - 1) * sizeof(user_t);
    if (myfile == NULL) 
    {
        fprintf(stderr, "cannot open file: users.dat");
        exit(1);
    }
    if (fseek(myfile, offset_to_user, SEEK_SET) != 0 ||
        fread(usr, sizeof(user_t), 1, myfile) != 1) 
    {
        fprintf(stderr, "cannot read user by id.\n");
        fclose(myfile);
        exit(1);
    }
    strcpy(usr->name, name);
    if (fseek(myfile, offset_to_user, SEEK_SET) != 0 ||
        fwrite(usr, sizeof(user_t), 1, myfile) != 1) 
    {
        fprintf(stderr, "cannot update usr");
        fclose(myfile);
        exit(1);
    }
    fclose(myfile);
}

int main(void)
{
    srand(time(NULL));
    user_t arr[USERS_SIZE];

    fillUsers(arr);
    printUsers(arr);
    writeUsers(arr);

    user_t *users = readUsers();
    printUsers(users);
    free(users);
    char name[8] = "isak";
    updateUserName(3, name);
    users = readUsers();
    printUsers(users);
    free(users);

    return 0;
}

