#define MAX_LINE_LENGTH 100

typedef struct employee_t {
    char name[MAX_LINE_LENGTH];
    float basic_pay;
} employee_t;

float getDA(employee_t employee);
float getGross(employee_t employee);
void print_employees(employee_t *employee, int size);
