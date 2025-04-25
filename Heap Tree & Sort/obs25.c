#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void display(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

void constructHeap(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int child = i;
        int parent = (child - 1)/2;
        while (child > 0 && arr[parent] < arr[child]) {
            int temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;
            child = parent;
            parent = (child-1)/2;
        }
    }
}

void heapSort(int *arr, int n) {
    constructHeap(arr, n);
    while (n > 0) {
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        n--;
        int child, parent = 0;
        while (parent * n + 1 < n) {
            int left = 2 * parent + 1;
            int right = left + 1;
            if (right < n && arr[right] > arr[left])
                child = right;
            else
                child = left;
            if (arr[parent] > arr[child])
                break;
            else {
                int temp = arr[parent];
                arr[parent] = arr[child];
                arr[child] = temp;
            }
        }
    }
}

void insert(int *arr, int *size, int data) {
    if (*size == MAX)
        return;
    (*size)++;
    arr[(*size) - 1] = data;
    constructHeap(arr, *size);
}

int delete(int *arr, int *size) {
    if (size == 0) return 0;
    int data = arr[0];
    for (int i = 0; i < (*size) - 1; i++)
        arr[i] = arr[i+1];
    (*size)--;
    constructHeap(arr, *size);
    return data;
}

int main() {
    int n;
    printf("Enter Number of Elements: ");
    scanf("%i", &n);
    int arr[MAX];
    printf("Enter Elements (a b c...): ");
    for (int i = 0; i < n; i++) scanf("%i", &arr[i]);
    display(arr, n);
    constructHeap(arr, n);
    
    int choice = 0;
    int data = 0;
    while (choice != 5) {
        printf("1. Delete\n2. Insert\n3. Display\n4. Sort\n5. Exit\nEnter Your Choice: ");
        scanf("%i", &choice); printf("\n");
        
        switch (choice)
        {
        case 1:
            data = delete(arr, &n);
            printf("%i\n", data);
            break;
            
        case 2:
            printf("Enter data: ");
            scanf("%i", &data);
            insert(arr, &n, data);
            break;
            
        case 3:
            display(arr, n);
            break;
            
        case 4:
            heapSort(arr, n);
            break;

        case 5:
            printf("Bye Bye!\n");
            break;

        default:
            printf("Invalid Choice!\n");
            break;
        }
        printf("\n");
    }
    return 0;
}