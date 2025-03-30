#include <stdio.h>

void bubbleSort(int *arr, int n) {
  for (int i = n - 1; i > 0; i--)
    for (int j = 0; j < i; j++)
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
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
  bubbleSort(arr, n);
  display(arr, n);
  return 0;
}
