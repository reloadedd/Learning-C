#include <stdio.h>
#include <stdlib.h>

#define EMPLOYEES_NUMBER	2
#define MAX_NAME_LENGTH		30


struct Employee {
	char last_name[MAX_NAME_LENGTH];
	char first_name[MAX_NAME_LENGTH];
	char title[MAX_NAME_LENGTH];
	int id;
	int ssn;
};

struct CompanyEmployees {
	struct Employee employee[EMPLOYEES_NUMBER];
};

int main(int argc, char const *argv[])
{
	struct CompanyEmployees employees;

	// Get user input
	for (int i = 0; i < EMPLOYEES_NUMBER; ++i) {
		printf("Enter the employee's first name: ");
		scanf("%s", employees.employee[i].first_name);

		printf("Enter the employee's last name: ");
		scanf("%s", employees.employee[i].last_name);

		printf("Enter the employee's ID number: ");
		scanf("%d", &employees.employee[i].id);

		printf("Enter the last 4 digits of the employee's SSN: ");
		scanf("%d", &employees.employee[i].ssn);

		printf("Enter the employee's job title (do not include the word 'Engineer'): ");
		scanf("%s", employees.employee[i].title);

		printf("\n");
	}

	// Display employee's credentials
	for (int i = 0; i < EMPLOYEES_NUMBER; ++i) {
		printf("Employee information for %s %s:\n", employees.employee[i].first_name,
			employees.employee[i].last_name);
		printf("ID: %d\n", employees.employee[i].id);
		printf("SSN: %d\n", employees.employee[i].ssn);
		printf("Title: %s Engineer\n\n", employees.employee[i].title);
	}

	return 0;
}