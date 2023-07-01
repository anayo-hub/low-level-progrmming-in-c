#include <stdio.h>

int main() {
    int height;

    // Prompt the user for the height of the pyramid
    do {
        printf("Enter the height of the pyramid (between 1 and 8): ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);

    // Print the pyramid
    for (int i = 0; i < height; i++) {
        // Print spaces
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }

        // Print a gap between the two halves of the pyramid
        printf("  ");

        // Print the other half of the pyramid
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
