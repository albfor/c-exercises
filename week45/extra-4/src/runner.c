#include <stdio.h>
#include <string.h>
#include "employee.h"

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while (0)
#define _verify(test) do { int r = test(); tests_run++; if (r) return r; } while (0)

int da_01() {
    employee_t employee = {"Albin", 100};
    _assert(getDA(employee) == 52);
    return 0;
}

int gross_01() {
    employee_t employee = {"Albin", 100};
    _assert(getGross(employee) == 152);
    return 0;
}

int print_employees_01() {
    employee_t employees[3];
    strcpy(employees[0].name, "Albin");
    employees[0].basic_pay = 100;
    strcpy(employees[1].name, "Bob");
    employees[1].basic_pay = 1000;
    strcpy(employees[2].name, "Charlie");
    employees[2].basic_pay = 500;

    print_employees(employees, 3);
    return 0;
}

int all_tests() {
    _verify(da_01);
    _verify(gross_01);
    _verify(print_employees_01);
    return 0;
}

int main(int argc, char** argv) {
    int result = all_tests();

    if (result == 0)
        printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
