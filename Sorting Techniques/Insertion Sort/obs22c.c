#include <stdio.h>

void insertionSort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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
  insertionSort(arr, n);
  display(arr, n);
  return 0;
}
