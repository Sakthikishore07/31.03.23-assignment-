#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int eno;
    char ename[50];
    float salary;
};

int main() {
    struct employee emp[100];
    int n, i, max_index;
    float max_salary;
    
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter details of employee %d:\n", i+1);
        printf("Employee number: ");
        scanf("%d", &emp[i].eno);
        printf("Employee name: ");
        scanf("%s", emp[i].ename);
        printf("Employee salary: ");
        scanf("%f", &emp[i].salary);
    }
    
    max_salary = emp[0].salary;
    max_index = 0;
    
    for (i = 1; i < n; i++) {
        if (emp[i].salary > max_salary) {
            max_salary = emp[i].salary;
            max_index = i;
        }
    }
    
    printf("\nDetails of employee with highest salary:\n");
    printf("Employee number: %d\n", emp[max_index].eno);
    printf("Employee name: %s\n", emp[max_index].ename);
    printf("Employee salary: %.2f\n", emp[max_index].salary);
    
    return 0;
}

