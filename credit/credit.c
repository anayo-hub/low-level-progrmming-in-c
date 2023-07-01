#include <stdio.h>

// Function to get the sum of the digits
int getDigitSum(int num)
{
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to validate credit card number using Luhn's algorithm
int validateCreditCard(long long int cardNumber)
{
    int isSecondDigit = 0;
    int sum = 0;
  
    // Traverse the card number from right to left
    while (cardNumber > 0) {
        int digit = cardNumber % 10;
        
        if (isSecondDigit) {
            digit *= 2;
            digit = getDigitSum(digit);
        }
  
        sum += digit;
  
        cardNumber /= 10;
        isSecondDigit = !isSecondDigit;
    }
  
    // If the sum is divisible by 10, the card number is valid
    return (sum % 10 == 0);
}

int main()
{
    long long int cardNumber;
  
    printf("Enter the credit card number: ");
    scanf("%lld", &cardNumber);
  
    // Validate the credit card number
    if (validateCreditCard(cardNumber)) {
        printf("Valid credit card number.\n");
    } else {
        printf("Invalid credit card number.\n");
    }
  
    return 0;
}
