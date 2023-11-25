#include <stdio.h>
#include <string.h>
#include "employee.h"

#define DA_RATIO 0.52

float getDA(employee_t employee)
{
    return employee.basic_pay * DA_RATIO;
}

float getGross(employee_t employee)
{
    return getDA(employee) + employee.basic_pay;
}

void print_employees(employee_t *employees, int size)
{
    printf("name\tgross\n------------------------------\n");

    for (int i = 0; i < size; i++) {
        printf("%s\t%.2f\n", employees[i].name, getGross(employees[i]));
    }
}

int main(void)
{
    return 0;
}

