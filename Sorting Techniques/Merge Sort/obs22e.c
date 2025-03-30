#include <stdio.h>

void merge(int *arr, int low, int mid, int high) {
  int i = low, j = mid + 1, k = low;
  int temp[high - low + 1];
  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
      temp[k] = arr[i];
      i++;
    } else {
      temp[k] = arr[j];
      j++;
    }
    k++;
  }
  while (i <= mid) {
    temp[k] = arr[i];
    i++;
    k++;
  }
  while (j <= high) {
    temp[k] = arr[j];
    j++;
    k++;
  }
  for (int k = low; k <= high; k++)
    arr[k] = temp[k];
}

void mergeSort(int *arr, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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
  mergeSort(arr, 0, n - 1);
  display(arr, n);
  return 0;
}
