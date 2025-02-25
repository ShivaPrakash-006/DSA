#include <stdio.h>
#define MAX 5

int isFull(char *queue, int f, int r)
{
  return ((f == r + 1) || (r == MAX - 1 && f == 0));
}

int isEmpty(char *queue, int f, int r)
{
  return f == -1;
}

void insertFront(char *queue, int *f, int *r, char data)
{
  if (isFull(queue, *f, *r)) {
    printf("Queue is Full\n");
    return;
  }
  if (isEmpty(queue, *f, *r)) (*r) = (*f) = 0;
  else if ((*f) == 0) (*f) = MAX - 1;
  else (*f)--;
  queue[*f] = data;
}

void insertRear(char *queue, int *f, int *r, char data)
{
  if (isFull(queue, *f, *r)) {
    printf("Queue is Full\n");
    return;
  }
  if (isEmpty(queue, *f, *r)) (*r) = (*f) = 0;
  else if ((*r) == MAX - 1) (*r) = 0;
  else (*r)++;
  queue[*r] = data;
}

char deleteFront(char *queue, int *f, int *r)
{
  if (isEmpty(queue, *f, *r)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  char data = queue[*f];
  if ((*f) == (*r)) (*f) = (*r) = -1;
  else if ((*f) == MAX - 1) (*f) = 0;
  else (*f)++;
  return data;
}

char deleteRear(char *queue, int *f, int *r)
{
  if (isEmpty(queue, *f, *r)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  char data = queue[*r];
  if ((*f) == (*r)) (*f) = (*r) = -1;
  else if ((*r) == 0) (*r) = MAX - 1;
  else (*r)--;
  return data;
}

char peekFront(char *queue, int f, int r)
{
  if (isEmpty(queue, f, r)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  return queue[f];
}

char peekRear(char *queue, int f, int r)
{
  if (isEmpty(queue, f, r)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  return queue[r];
}

void display(char *queue, int f, int r)
{
  if (isEmpty(queue, f, r)) {
    printf("Queue is Empty\n");
    return;
  }
  if (f <= r) for (int i = f; i <= r; i++) printf("%c ", queue[i]);
  else {
    for (int i = f; i < MAX; i++) printf("%c ", queue[i]);
    for (int i = 0; i <= r; i++) printf("%c ", queue[i]);
  }
  printf("\n");
}

int main(int argc, int *argv[])
{
  int choice = 0, r = -1, f = -1;
  char data = '\0';

  char queue[MAX] = {};

  while (choice != 5) {
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter Your Choice: ");
    scanf("%i", &choice); printf("\n");

    switch (choice) {
      case 1:
        printf("Enter Data: ");
        do data = getchar(); while (data == '\n' || data == '\0');

        printf("1. Front\n2. Rear\nEnter Your Choice: ");
        scanf("%i", &choice);

        switch (choice) {
          case 1:
            insertFront(queue, &f, &r, data);
            break;

          case 2:
            insertRear(queue, &f, &r, data);
            break;

          case 3:
            printf("Invalid Choice\n");
        }
        display(queue, f, r);
        break;

      case 2:
        printf("1. Front\n2. Rear\nEnter Your Choice: ");
        scanf("%i", &choice);

        switch (choice) {
          case 1:
            data = deleteFront(queue, &f, &r);
            break;

          case 2:
            data = deleteRear(queue, &f, &r);
            break;

          case 3:
            printf("Invalid Choice\n");
            data = '\0';
        }

        if (data) printf("%c has been processed\n", data);
        display(queue, f, r);
        break;

      case 3:
        printf("1. Front\n2. Rear\nEnter Your Choice: ");
        scanf("%i", &choice);

        switch (choice) {
          case 1:
            data = peekFront(queue, f, r);
            break;

          case 2:
            data = peekRear(queue, f, r);
            break;

          case 3:
            printf("Invalid Choice\n");
            data = '\0';
        }
        if (data) printf("%c is in the front\n", data);
        break;

      case 4:
        display(queue, f, r);
        break;

      case 5:
        printf("Bye Bye!\n");
        break;

      default:
        printf("Invalid Choice\n");
    }
    printf("\n");
  }
  
  return 0;
}
