#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>

struct employeeDetails{
	// for all employees
	char id[10]; 
	char name[15];
	char statusCode[10];
	int hoursWorked;
	float deductions;
	
	float salary; // variable declaration used for regular employee, salary for the whole month
	float basicRate; // variable declaration used for casual employee, rate (payment) for everyday, needed to solve monthly salary
	
};

struct employeeDetails employees[100];

int totalEmployee = 0;
int menuInput;
int addEmployeeMenuInput;
int displayEmployeeInput;

char genEmployeeNum[] = "2023-"; // starting number for generated employee number
int base = 1700;
int counter = 1;
//salary
float basicSalary; // for regular, input salary meaning per month
float basicRate; // for casual, input rate meaning per day
float overtime;

void addNewEmployee(){
	char tempId[10];
	char tempStatus[10];
	
	sprintf(tempId, "%s%d", genEmployeeNum, base + counter);
	strcpy(employees[counter].id, tempId);
		
	printf("Please enter your name: ");
	scanf(" %[^\n]%*c", &employees[counter].name);

	printf("Please enter your employment status: ");
	scanf(" %[^\n]%*c", &tempStatus);
			
	if (strcmp(tempStatus,"r") == 0 || strcmp(tempStatus, "R") == 0){
		strcpy(employees[counter].statusCode, tempStatus);
		
		printf("Please enter your basic salary: "); 
		scanf("%f", &employees[counter].salary);
			
		printf("Please enter your worked hours for the month: "); 
		scanf("%d", &employees[counter].hoursWorked);
			
		printf("Please enter any deduction: "); 
		scanf("%f", &employees[counter].deductions);
		
		printf("\n");
				
		}else {
			strcpy(employees[counter].statusCode, tempStatus);
			printf("Please enter your basic rate: "); 
			scanf("%f", &employees[counter].basicRate); 
			
			printf("Please enter your worked hours for the month: "); 
			scanf("%d", &employees[counter].hoursWorked);
				
			printf("Please enter any deduction: "); 
			scanf("%f", &employees[counter].deductions);
		
		printf("\n");

	}
			
	counter++;
	totalEmployee++;
}

// to display the status code depending on the user input
char *status(char *code) {
	if (strcmp(code,"r") == 0 || strcmp(code, "R") == 0){
		code = "Regular";
	}else {
		code = "Casual";
	}
		
	return code; 
}

// function that solves both overtime payment of regular and casual employees
float computeOvertimePay(float basicPay , int hours){
	float totalOvertimePay;
	if (hours > 160) {
		int tempHour = hours - 160; 
		float tempBasicSalary = basicPay; 
		
		basicPay = ((basicPay / 2) + tempBasicSalary); 
		totalOvertimePay = basicPay * tempHour; 
	}else {
		return 0;
	}

	return totalOvertimePay;
} 

// function that solves the rate (daily payment) for regular employees
float calculateBasicPay(float salary){ 
	salary = salary / 160;
	
	return salary; 
}

// function that solves both net pay of regular and casual employees
float calculateNetPay(float salary, float overtimePay, float deductionss) {
    float totalNetPay = salary + overtimePay - deductionss; 

    return totalNetPay; 
}

// function that solves the complete (monthly) salary for casual employees
float calculateSalary(int hours, float casualSalary) { // for casual employee, complete salary for the month
	casualSalary = hours * casualSalary;

	return casualSalary;
}

void displayEmployees() {
	for (int i = 1; i < counter; i++) {
		printf("%s\t", employees[i].id);
		printf("%s\t", employees[i].name);
		printf("%s\t\t", status(employees[i].statusCode));
		
		if (strcmp(employees[i].statusCode,"r") == 0 || strcmp(employees[i].statusCode, "R") == 0) {
			printf("%.2f\t\t", employees[i].salary);
			printf("%.2f\t\t", computeOvertimePay(calculateBasicPay(employees[i].salary), employees[i].hoursWorked)); 
			printf("%.2f\t\t", employees[i].deductions);
			printf("%.2f\t", calculateNetPay(employees[i].salary, computeOvertimePay(calculateBasicPay(employees[i].salary), employees[i].hoursWorked), employees[i].deductions));
			
		}else {
			printf("%.2f\t\t", calculateSalary(employees[i].hoursWorked, employees[i].basicRate));
			printf("%.2f\t\t", computeOvertimePay(employees[i].basicRate, employees[i].hoursWorked)); 
			printf("%.2f\t\t", employees[i].deductions);
			printf("%.2f\t", calculateNetPay(calculateSalary(employees[i].hoursWorked, employees[i].basicRate), computeOvertimePay(employees[i].basicRate, employees[i].hoursWorked), employees[i].deductions)); 
		}

		printf("\n");	
	}
}

int main() {
	
	mainMenu:{
		system("cls");
		printf("\t\tWelcome Employee Management System!\n");
        printf("\t\tTotal Employee: %d\n\n\t", totalEmployee);
        printf("Menu :\n\n\t");
        printf("(1) Add Employee\n\t");
        printf("(2) Display All Employee\n\t");
        printf("(0) Exit\n\n\n\t");
        printf("Enter an integer: ");
        scanf("%d", &menuInput);
    
		switch(menuInput){
			case 1:
				goto addEmployee;
				break;
				
			case 2:
				goto displayEmployee;
				break;
					
			case 0:
				return 0;
				break;
					
			default:
				goto mainMenu;
				break;
				
		}
	}
	
	addEmployee:{
		system("cls");
		
		addNewEmployee();
		
		printf("\t\tEmployee/s has been added.\n");
		
		printf("\t\tDo you want to add another employee?\n");
		printf("\t(1) Yes\n\t");
	    printf("(2) No\n\t");
	    printf("Enter you choice: ");
	    scanf("%d", &addEmployeeMenuInput);
	    
	    switch(addEmployeeMenuInput){
	    	case 1:
	    		goto addEmployee;
	    		break;
	    	
	    	default:
	    		goto mainMenu;
	    		break;
		}

	}
	
	displayEmployee:{
		system("cls");
		
		displayEmployees();
		
		printf("\n\n\tOptions:\n\t");
		printf("(1) Return to Menu\n\t");
	    printf("(2) Add Employee\n\t");
	    printf("Enter you choice: ");
	    scanf("%d", &displayEmployeeInput);
	    
	    switch(displayEmployeeInput){
	    	case 2:
	    		goto addEmployee;
	    		break;
	    		
	    	default:
	    		goto mainMenu;
	    		break;

		}
	    
	}

	return 0;	
}
