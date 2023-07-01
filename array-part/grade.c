#include <stdio.h>
#include <stdlib.h>

int* findSquare (int* number){
   int square = *number * *number;
   *number = square;
   return number;
}

int main()
{
  int num = 21;

  printf("Result is %d\n", num);

  int* result = findSquare(&num);

   printf("Result is %d", num);

   return 0;
}