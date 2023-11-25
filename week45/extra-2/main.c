#include <stdio.h>
#include <string.h>
#define MAX_NUMBER_OF_NAMES 5 
#define MAX_NAME_LENGTH 100
int main(void)
{
    char first[MAX_NUMBER_OF_NAMES][MAX_NAME_LENGTH] = {"name", "name1", "name2", "name3", "name4"};
    char second[MAX_NUMBER_OF_NAMES][MAX_NAME_LENGTH] = {"sec-name", "sec-name1", "sec-name2", "sec-name3", "sec-name4"};
    char last[MAX_NUMBER_OF_NAMES][MAX_NAME_LENGTH] = {"last-name", "last-name1", "last-name2", "last-name3", "last-name4"};

    for (int i = 0; i < MAX_NUMBER_OF_NAMES; i++) {
        char employee_name[3*MAX_NAME_LENGTH + 2] = ""; // 3 since we allow first, seconde and third name 2 since we add spaces between the names.
        strcat(employee_name, first[i]);
        strcat(employee_name, " ");
        strcat(employee_name, second[i]);
        strcat(employee_name, " ");
        strcat(employee_name, last[i]);
        printf("%s\n", employee_name);
    }

    return 0;
}
