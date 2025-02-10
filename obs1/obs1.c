#include <stdio.h>

void traverse(int *arr, int n)
{
  printf("[");
  for (int i=0; i<n; i++)
    printf("%i ", arr[i]);
  printf("]\n");
}

void insert(int *arr, int *n, int data, int pos)
{
  if (*n == 99) { 
    printf("Overflow!\n");
    return;
  }

  if (pos > *n) {
    printf("Position higher than size!\n");
    return;
  }

  if (pos < 0) {
    printf("Position lower than 0!\n");
    return;
  }
  
  for (int i=*n; i>pos; i--)
    arr[i] = arr[i - 1];

  arr[pos] = data;
  (*n)++;
  traverse(arr, *n);
}

void delete(int *arr, int *n, int pos)
{
  if (*n==0) {
    printf("Underflow!\n");
    return;
  }

  if (pos > (*n)-1) {
    printf("Position higher than size!\n");
    return;
  }

  if (pos < 0) {
    printf("Position lower than 0!\n");
    return;
  }

  for (int i=pos; i<*n; i++)
    arr[i] = arr[i+1];

  (*n)--;
  traverse(arr, *n);
}

int search(int *arr, int n, int data)
{
  int pos = -1;

  if (n==0) {
    printf("Underflow!\n");
    return pos;
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] == data)
      pos = i;
  }

  return pos;
}

int main(){
  int arr[100] = {10, 20, 30, 40};
  int n, data, pos, choice;
  n = 4;
  choice = 0;
  while (choice != 5)
  {
    printf("1. Display the Array\n2. Insert Element Into Array\n3. Delete Element From Array\n4. Search the Array for a Value\n5. Exit\nEnter Your Choice: ");
    scanf("%i", &choice);
    printf("\n");
    switch (choice)
    {
      case 1:
        traverse(arr, n);
        break;
      case 2:
        printf("Enter Data and Position(data pos<%i): ", n + 1);
        scanf("%i %i", &data, &pos);
        insert(arr, &n, data, pos);
        break;
      case 3:
        printf("Enter Position(<%i): ", n);
        scanf("%i", &pos);
        delete(arr, &n, pos);
        break;
      case 4:
        printf("Enter Data: ");
        scanf("%i", &data);
        pos = search(arr, n, data);
        printf("Position of %i in Array: %i\n", data, pos);
        break;
      case 5:
        printf("Bye Bye!\n");
        break;
      default:
        printf("Enter A Valid Option");
    }

    printf("\n");
  }
  return 0;
}
