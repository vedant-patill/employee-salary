#include <stdio.h>
#include <string.h>

// Define structure for Employee
struct Employee {
    char name[50];
    char post[50];
    float basic;
    float ta;
    float hra;
    float gross_salary;
};

// Function to automatically assign a post based on basic salary
void assignPost(float basic, char *post) {
    if (basic >= 100000) {
        strcpy(post, "Director");
    } else if (basic >= 75000) {
        strcpy(post, "Manager");
    } else if (basic >= 50000) {
        strcpy(post, "Team Lead");
    } else if (basic >= 30000) {
        strcpy(post, "Senior Dev");
    } else if (basic >= 15000) {
        strcpy(post, "Junior Dev");
    } else {
        strcpy(post, "Intern");
    }
}

int main() {
    int n, i;

    printf("Enter the number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }
    getchar(); // Consume the newline character left by scanf

    // Array of structures to store employee details
    struct Employee emp[n];

    // Input loop
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Employee %d ---\n", i + 1);

        printf("Enter Employee Name: ");
        fgets(emp[i].name, sizeof(emp[i].name), stdin);
        emp[i].name[strcspn(emp[i].name, "\n")] = 0; // Remove trailing newline

        printf("Enter Basic Salary: ");
        scanf("%f", &emp[i].basic);
        getchar(); // Consume newline

        // Automatically generate post based on the basic salary
        assignPost(emp[i].basic, emp[i].post);

        // Calculations according to formulas
        emp[i].ta = 0.23 * emp[i].basic;           // TA is 23% of basic
        emp[i].hra = 0.30 * emp[i].basic;          // HRA is 30% of basic
        emp[i].gross_salary = emp[i].basic + emp[i].ta + emp[i].hra; // Gross = Basic + TA + HRA
    }

    // Output in Tabular Form
    printf("\n\n");
    printf("===================================================================================\n");
    printf("                                EMPLOYEE PAYROLL SYSTEM                            \n");
    printf("===================================================================================\n");
    printf("%-20s %-15s %-12s %-10s %-10s %-15s\n", "Name", "Post", "Basic", "TA (23%)", "HRA (30%)", "Gross Salary");
    printf("-----------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-20s %-15s %-12.2f %-10.2f %-10.2f %-15.2f\n",
               emp[i].name,
               emp[i].post,
               emp[i].basic,
               emp[i].ta,
               emp[i].hra,
               emp[i].gross_salary);
    }
    printf("===================================================================================\n");

    return 0;
}