#include <stdio.h>

void selectionSort(int *arr, int n) {
  for (int pos = 0; pos < n - 1; pos++) {
    int min = pos;
    for (int i = pos + 1; i < n; i++)
      if (arr[i] < arr[min])
        min = i;

    if (min != pos) {
      int temp = arr[min];
      arr[min] = arr[pos];
      arr[pos] = temp;
    }
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
  selectionSort(arr, n);
  display(arr, n);
  return 0;
}
