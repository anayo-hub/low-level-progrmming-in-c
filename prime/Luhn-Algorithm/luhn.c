#include <stdio.h>
#include <stdbool.h>

// Function to check if a credit card number is valid using Luhn's algorithm
bool isValidCardNumber(long long cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    while (cardNumber > 0) { // 4567123412341234
        int digit = cardNumber % 10;

        if (doubleDigit) { // when doubleDigit turns true
            digit *= 2;
            if (digit > 9) { // when a doubled number is more than 9
                digit = (digit % 10) + 1;
            }
        }

        sum += digit; // anything cardNumber % 10 returns per iteration
        doubleDigit = !doubleDigit; //chnages per interation
        cardNumber /= 10; //check if number is valid or not by ensuring division retuns 0 per iteration
    }

    return (sum % 10) == 0; //true or false
}

// Function to determine the type of credit card
void checkCardType(long long cardNumber) {
    int length = 0;
    long long temp = cardNumber;

    while (temp > 0) {
        temp /= 10;
        length++;
    }

    // Check the card type based on the number of digits and starting digits
    if (length == 16 && (cardNumber >= 4000000000000000 && cardNumber <= 4999999999999999)) {
        printf("Card Type: Visa\n");
    } else if ((length == 16 || length == 19) && (cardNumber >= 5100000000000000 && cardNumber <= 5599999999999999)) {
        printf("Card Type: Mastercard\n");
    } else if (length == 15 && (cardNumber >= 340000000000000 && cardNumber <= 349999999999999) ||
               length == 15 && (cardNumber >= 370000000000000 && cardNumber <= 379999999999999)) {
        printf("Card Type: AMEX\n");
    } else if ((length == 19 || length == 20) && (cardNumber >= 5060000000000000000 && cardNumber <= 5060999999999999999)) {
        printf("Card Type: Verve\n");
    } else {
        printf("Card Type: Unknown\n");
    }
}

int main() {
    long long cardNumber;

    printf("Enter the credit card number: ");
    scanf("%lld", &cardNumber);

    if (isValidCardNumber(cardNumber)) {
        printf("The credit card number is valid.\n");
        checkCardType(cardNumber);
    } else {
        printf("Invalid credit card number.\n");
    }

    return 0;
}
