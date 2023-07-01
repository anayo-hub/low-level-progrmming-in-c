#include <stdio.h>

int main() {
    int startSize, endSize;
    int population;
    int year = 0;

    do
    {
        startSize = get_int("make the start size: ");
    }
    while (startSize < 9);

    do
    {
      endSize = get_int("make the end size: ");
    }
    while(endSize < startSize);

    population = startSize;

    while (population < endSize) {
        int newLlamas = population / 3;
        int deceasedLlamas = population / 4;
        population += newLlamas - deceasedLlamas;
        year++;
    }

    printf("It takes %d years for the population to reach %d llamas.\n", year, endSize);

    return 0;
}
