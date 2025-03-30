#include <stdio.h>

int partition(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low + 1, j = high;
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i < j) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  arr[low] = arr[j];
  arr[j] = pivot;
  return j;
}

void quickSort(int *arr, int low, int high) {
  if (low < high) {
    int j = partition(arr, low, high);
    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
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
  quickSort(arr, 0, n - 1);
  display(arr, n);
  return 0;
}
