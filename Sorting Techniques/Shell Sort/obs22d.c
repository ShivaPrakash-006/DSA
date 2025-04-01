#include <stdio.h>

void shellSort(int *arr, int n) {
  int gap = n / 2;
  int swapped;
  do {
    do {
      swapped = 0;
      for (int i = 0; i < n - gap; i++)
        if (arr[i] > arr[i + gap]) {
          int temp = arr[i];
          arr[i] = arr[i + gap];
          arr[i + gap] = temp;
          swapped = 1;
        }
    } while (swapped == 1);
    gap = gap / 2;
  } while (gap > 0);
}

void display(int *arr, int n) {
  for (int i = 0; i < n; i++)
    printf("%i ", arr[i]);
  printf("\n");
}

int main() {
  int n;
  printf("Enter Number of Elements: ");
  scanf("%i", &n);
  int arr[n] = {};
  printf("Enter Elements (a b c...): ");
  for (int i = 0; i < n; i++)
    scanf("%i", &arr[i]);
  display(arr, n);
  shellSort(arr, n);
  display(arr, n);
  return 0;
}
