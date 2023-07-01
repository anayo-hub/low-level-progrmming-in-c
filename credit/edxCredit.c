#include <stdio.h>
#include <cs50.h> // CS50 library for user prompts

// Function to get the sum of the digits
int getDigitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10; // Add the last digit to the sum
        num /= 10; // Remove the last digit from the number
    }
    return sum;
}

// Function to validate credit card number using Luhn's algorithm
string validateCreditCard(long long int *cardNumber)
{
    int isSecondDigit = 0;
    int sum = 0;
    long long int num = *cardNumber; // Get the card number value using the pointer

    // Traverse the card number from right to left
    while (num > 0)
    {
        int digit = num % 10; // Get the last digit of the card number

        if (isSecondDigit)
        {
            digit *= 2; // Multiply every other digit by 2
            digit = getDigitSum(digit); // Get the sum of the digits of the product
        }

        sum += digit; // Add the current digit to the sum

        num /= 10; // Remove the last digit from the card number
        isSecondDigit = !isSecondDigit; // Toggle the flag for every other digit
    }

    // Check the card type and validity
    if (sum % 10 == 0)
    {
        // Check the card number length and starting digits for specific card types
        if ((*cardNumber >= 340000000000000 && *cardNumber < 350000000000000) || (*cardNumber >= 370000000000000
                && *cardNumber < 380000000000000))
        {
            return "AMEX";
        }
        else if (*cardNumber >= 5100000000000000 && *cardNumber < 5600000000000000)
        {
            return "MASTERCARD";
        }
        else if ((*cardNumber >= 4000000000000 && *cardNumber < 5000000000000) || (*cardNumber >= 4000000000000000
                 && *cardNumber < 5000000000000000))
        {
            return "VISA";
        }
        else
        {
            return "INVALID";
        }
    }
    else
    {
        return "INVALID";
    }
}

int main(void)
{
    long long int cardNumber;

    cardNumber = get_long_long("Enter the credit card number: "); // Prompt the user for the credit card number using CS50 library

    // Validate the credit card number and determine the card type
    string cardType = validateCreditCard(&cardNumber); // Pass the address of cardNumber

    // Print the card type
    printf("%s\n", cardType);

    return 0;
}
