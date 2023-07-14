#include <stdio.h>

#define MAX_EMPLOYEES 100

struct Employee {
    char number[11];
    char name[16];
    char status;
    int hoursWorked;
    float deductions;
    float basicSalary;
    float overtimePay;
    float netPay;
};

void calculateNetPay(struct Employee* emp) {
    if (emp->status == 'R') {
        float basicRate = emp->basicSalary / 160.0;
        if (emp->hoursWorked > 160) {
            float overtimeRate = basicRate * 1.5;
            emp->overtimePay = (emp->hoursWorked - 160) * overtimeRate;
        } else {
            emp->overtimePay = 0.0;
        }
        emp->netPay = emp->basicSalary + emp->overtimePay - emp->deductions;
    } else if (emp->status == 'C') {
        emp->overtimePay = 0.0;
        if (emp->hoursWorked > 160) {
            float overtimeRate = emp->basicSalary / 160.0 * 1.5;
            emp->overtimePay = (emp->hoursWorked - 160) * overtimeRate;
        }
        emp->netPay = emp->basicSalary + emp->overtimePay - emp->deductions;
    }
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEmployee #%d\n", i + 1);
        printf("Employee Number: ");
        scanf("%s", employees[i].number);
        printf("Employee Name: ");
        scanf("%s", employees[i].name);
        printf("Status Code (R for Regular, C for Casual): ");
        scanf(" %c", &employees[i].status);
        printf("Hours Worked: ");
        scanf("%d", &employees[i].hoursWorked);
        printf("Deductions: ");
        scanf("%f", &employees[i].deductions);

        if (employees[i].status == 'R') {
            printf("Basic Salary: ");
            scanf("%f", &employees[i].basicSalary);
        } else if (employees[i].status == 'C') {
            printf("Basic Rate: ");
            scanf("%f", &employees[i].basicSalary);
            employees[i].basicSalary *= employees[i].hoursWorked;
        }

        calculateNetPay(&employees[i]);
    }

    printf("\nABC COMPANY\nMakati City\n\nPayroll\n\n");
    printf("  Employee\tEmployee\tStatus\tBasic\tOvertime\tDeductions\tNet\n");
    printf("  Number\tName\t\t\tSalary\tPay\t\tPay\n");

    for (int i = 0; i < n; i++) {
        printf("%10s\t%15s\t%s\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",
            employees[i].number, employees[i].name,
            (employees[i].status == 'R' ? "Regular" : "Casual"),
            employees[i].basicSalary, employees[i].overtimePay,
            employees[i].deductions, employees[i].netPay);
    }

    return 0;
}
