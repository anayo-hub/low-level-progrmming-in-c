#include <stdio.h>
#include <stdarg.h>

double divideNumbers(int count, ...) {
    va_list args;
    va_start(args, count);

    double result = va_arg(args, double);  // Retrieve the first number as the initial value

    for (int i = 1; i < count; i++) {
        double num = va_arg(args, double);
        result /= num;  // Division operation
    }

    va_end(args);
    return result;
}

int main() {
    double result = divideNumbers(3, 24.0, 2.0, 3.0);
    printf("Result: %lf\n", result);

    return 0;
}
