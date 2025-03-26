#include <stdio.h>
#include <stdlib.h>
/*
POWER
FACTORIAL
FIBONACCI
GCD
SUM
DEC TO BIN
*/

float power(int base, int pow) {
  if (pow == 0)
    return 1;
  else if (pow == 1)
    return base;
  else if (pow < 0)
    return 1.f / power(base, abs(pow));
  else
    return (float)base * power(base, pow - 1);
}

int fact(int num) {
  if (num == 1)
    return 1;
  else
    return num * fact(num - 1);
}

int fib(int n) {
  if (n <= 1)
    return 0;
  if (n == 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int gcd(int a, int b) {
  int x = (a > b) ? a : b;
  int y = (a < b) ? a : b;

  if (y == 0)
    return x;
  else
    return gcd(y, (x % y));
}

int sum(int n) {
  if (n <= 1)
    return 1;
  else
    return n + sum(n - 1);
}

long int bin(int decimal_number) {
  if (decimal_number == 0)
    return 0;
  else
    return (decimal_number % 2 + 10 * bin(decimal_number / 2));
}

int main() {
  int choice, num1, num2;
  choice = 0;
  while (choice != 7) {
    printf(
        "1. Power\n2. Factorial\n3. Fibonacci Series\n4. GCD\n5. Sum of n "
        "Natural Numbers\n6. Decimal to Binary\n7. Exit\nEnter Your Choice: ");
    scanf("%i", &choice);
    printf("\n");
    switch (choice) {
    case 1:
      printf("Enter Base and Power (Base Power): ");
      scanf("%i %i", &num1, &num2);
      printf("%i^%i = %f\n", num1, num2, power(num1, num2));
      break;

    case 2:
      printf("Enter Number: ");
      scanf("%i", &num1);
      printf("%i! = %i\n", num1, fact(num1));
      break;

    case 3:
      printf("Enter Number of Terms: ");
      scanf("%i", &num1);
      for (int i = 1; i <= num1; i++)
        printf("%i ", fib(i));
      printf("\n");
      break;

    case 4:
      printf("Enter Numbers (num1 num2): ");
      scanf("%i %i", &num1, &num2);
      printf("GCD of %i and %i is %i\n", num1, num2, gcd(num1, num2));
      break;

    case 5:
      printf("Enter Number of terms: ");
      scanf("%i", &num1);
      printf("Sum of first %i natural numbers is %i\n", num1, sum(num1));
      break;

    case 6:
      printf("Enter Decimal Number: ");
      scanf("%i", &num1);
      printf("%i in binary: %li\n", num1, bin(num1));
      break;

    case 7:
      printf("Bye Bye!\n");
      break;

    default:
      printf("Invalid Choice!\n");
      break;
    }
    printf("\n");
  }
}
