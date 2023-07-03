#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);   // Function declaration for calc_hours

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");    // Prompt the user for the number of weeks
    int hours[weeks];   // Declare an array to store hours based on the number of weeks

    for (int i = 0; i < weeks; i++)     // Loop through each week
    {
        hours[i] = get_int("Week %i HW Hours: ", i + 1);    // Prompt the user for hours for each week
    }

    char output;
    do
    {
        output = toupper(
                     get_char("Enter T for total hours, A for average hours per week: "));   // Prompt the user for the desired output option
    }
    while (output != 'T' && output != 'A');   // Repeat the prompt until a valid option is selected

    printf("%.1f hours\n", calc_hours(hours, weeks, output));     // Print the result returned by the calc_hours function

    return 0;   // Return 0 to indicate successful program execution
}

float calc_hours(int hours[], int weeks, char output)   // Function definition for calc_hours
{
    int total = 0;    // Variable to store the total hours

    for (int i = 0; i < weeks; i++)    // Loop through each week
    {
        if (output == 'T')
        {
            total += hours[i];   // Accumulate total hours for total calculation
        }
        else if (output == 'A')
        {
            total += hours[i];   // Accumulate total hours for average calculation
        }
    }

    if (output == 'A')
    {
        return (float) total / weeks;   // Calculate average using floating-point division
    }

    return total;    // Return the total hours
}
