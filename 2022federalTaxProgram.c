

/*
Program gets the users results based off the assumption that they did not 
place withholdings throughout the year on their pay cycles
*/


#include <stdio.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BRACKETS 7
#define STUDENT_DEDUCTION 2500
#define CHILD_DEDUCTION 2000  // Define deduction per child

// Structure to store tax brackets and rates
typedef struct 
{
    float brackets[BRACKETS];
    float rates[BRACKETS];
} TaxTable;

// Tax data for each filing status
const TaxTable taxData[] = {
    { {10275, 41775, 89075, 170050, 215950, 539900, FLT_MAX}, {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37} }, // Single
    { {20550, 83550, 178150, 340100, 431900, 647850, FLT_MAX}, {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37} }, // Married Jointly
    { {14650, 55900, 89050, 170050, 215950, 539900, FLT_MAX}, {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37} }  // Head of Household
};

// Function to calculate tax
float calculateTax(float income, const TaxTable *table) 
{
    float tax = 0;
    float previousBracket = 0;
    for (int i = 0; i < BRACKETS; i++) //start looping through all tax brackets 
    {
        if (income > table->brackets[i])//If income > current bracket, apply tax 
        {
            tax += (table->brackets[i] - previousBracket) * table->rates[i];// sum previous tax w current tax
            previousBracket = table->brackets[i];//update the tax bracket to new upper limit
        } 
        else 
        {
            tax += (income - previousBracket) * table->rates[i];// If income <= current bracket, calculate the tax for remaining income
            break;
        }
    }
    return tax;
}

int main() 
{
    char *filingStatus[] = {"single", "married jointly", "head of household"};
    char input[50];
    float income;

    // Get filing status....
    printf("Enter your filing status (Single, Married Jointly, Head of Household): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline
    for (int i = 0; input[i]; i++) input[i] = tolower(input[i]); // Convert to lowercase

    int status = -1;
    for (int i = 0; i < 3; i++) 
    {
        if (strcmp(input, filingStatus[i]) == 0) 
        {
            status = i;
            break;
        }
    }
    if (status == -1) 
    {
        printf("Invalid filing status.\n");
        return 1;
    }

    // Get income
    printf("Enter your income: ");
    scanf("%f", &income);
    if (income < 0) 
    {
        printf("Invalid income.\n");
        return 1;
    }

    // see if they get tax deduction for being in college....
    char studentResponse[10];
    printf("Are you a college student? (yes/no): ");
    scanf("%s", studentResponse);
    for (int i = 0; studentResponse[i]; i++) studentResponse[i] = tolower(studentResponse[i]);

    if (strcmp(studentResponse, "yes") == 0) 
    {
        printf("You qualify for a $2500 student tax deduction!\n");
        income = income - STUDENT_DEDUCTION;
        if (income < 0) 
        {
            income = 0;
        }
    }

    // Ask if claiming children
    int numChildren;
    printf("How many children are you claiming? ");
    scanf("%d", &numChildren);
    if (numChildren < 0) 
    {
        printf("Invalid number of children.\n");
        return 1;
    }

    // Deduct the child deduction from the income
    float childDeduction = numChildren * CHILD_DEDUCTION;
    income = income - childDeduction;
    

    // Calculate and print tax.....
    float totalTax = calculateTax(income, &taxData[status]);
    printf("Total tax owed: $%.2f\n", totalTax);

    return 0;
}




