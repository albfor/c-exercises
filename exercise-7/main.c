#include <stdio.h>

/**
* Definition of date struct
*/
typedef struct date_t {
    int day;
    int month;
    int year;
} date_t;

int main(void)
{
    date_t new_date;
    printf("Enter date (DD MM YYYY): ");
    // Read date data from user
    scanf("%d %d %d", &new_date.day, &new_date.month, &new_date.year); 
    // Print data using YYYY-MM-DD format
    printf("%04d-%02d-%02d\n", new_date.year, new_date.month, new_date.day);

    return 0;
}
