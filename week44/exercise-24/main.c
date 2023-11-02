#include <stdio.h>
#include <stdbool.h>

bool valid_date(int year, int month, int day);
bool valid_time(int hour, int minute, int second);

enum MONTHS {
    JANUARY = 1, 
    FEBRUARY, 
    MARCH, 
    APRIL, 
    MAY, 
    JUNE, 
    JULY, 
    AUGUST, 
    SEPTEMBER, 
    OCTOBER, 
    NOVEMBER, 
    DECEMBER
};

int main(void)
{
    unsigned short int year, month, day, hour, minute, second;

    printf("enter date (YYYY-MM-DD HH:mm:ss): ");
    scanf("%hd-%hd-%hd %hd:%hd:%hd", &year, &month, &day, &hour, &minute, &second);

    if (valid_date(year, month, day) && valid_time(hour, minute, second))
        printf("valid date");

    return 0;
}

bool valid_date(int year, int month, int day) 
{
    if (year > 9999) {
        printf("invalid year 0000..9999\n");
        return false;
    }

    switch (month) {
    // months with 31 days
    case JANUARY:
    case MARCH:
    case MAY:
    case JULY:
    case AUGUST:
    case OCTOBER:
    case DECEMBER:
        if (day > 31) {
            printf("invalid day 00..31\n");
            return false;
        }
        break;
    // months with 30 days
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        if (day > 30) {
            printf("invalid day 00..30\n");
            return false;
        }
        break;
    // february
    case FEBRUARY:
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    if (day > 29) {
                        printf("invalid day 00.29\n");
                        return false;
                    }
                }
                else {
                    if (day > 28) {
                        printf("invalid day 00..28\n");
                        return false;
                    }
                }
            }
            else if (day > 29) {
                printf("invalid day 00..29\n");
                return false;
            }
        }
        else if (day > 28) {
            printf("invalid day 00..28\n");
            return false;
        }
        break;
    default:
        printf("invalid month 01..12\n");
        return false;
    }

    return true;
}

bool valid_time(int hour, int minute, int second)
{
    if (hour > 23) {
        printf("invalid hour 00..23\n");
        return false;
    }
    if (minute > 59) {
        printf("invalid minute 00..59\n");
        return false;
    }
    if (second > 59) {
        printf("invalid second 00..59\n");
        return false;
    }

    return true;
}

