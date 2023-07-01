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
        // Print hashes
        for (int j = 0; j <= i; j++) {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
