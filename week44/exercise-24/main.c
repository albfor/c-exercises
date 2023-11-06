#include <stdio.h>
#include <stdbool.h>

bool valid_date(int year, int month, int day);
bool valid_time(int hour, int minute, int second);
bool is_leap_year(int year);

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

/**
 * @return true if @year is in range of 0..9999, @month is in range 1..12 and
 *                 @day is a valid day for the given year and month
 */
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
        if (day > 29 || (day == 29 && !is_leap_year(year))) {
            printf("day can only be greater than 28 if leap year.\n");
            return false;
        } 
        break;
    default:
        printf("invalid month 01..12\n");
        return false;
    }

    return true;
}

/**
 * @return true if @hour is in the range 0..23, @minute is in the range 0..59
 *                 and @second in the range 0..59.
 */
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

/**
 * @return true if @year is a leap year
 */
bool is_leap_year(int year)
{
    if (year % 4 != 0) {
        return false;
    }

    if (year % 100 == 0 && year % 400 != 0) {
        return false;
    }

    return true;
}

