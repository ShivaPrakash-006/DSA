#include <stdio.h>
#define MAX 3

int isFull(char *queue, int f, int r)
{
  return r == MAX-1;
}

int isEmpty(char *queue, int f, int r)
{
  return f == -1;
}

void enqueue(char *queue, int *f, int *r, char data)
{
  if (isFull(queue, *f, *r)) {
    printf("Queue is Full\n");
    return;
  }
  if (isEmpty(queue, *f, *r)) (*r) = (*f) = 0;
  else (*r)++;
  queue[*r] = data;
}

char dequeue(char *queue, int *f, int *r)
{
  if (isEmpty(queue, *f, *r)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  char data = queue[*f];
  if ((*f) == (*r)) (*f) = (*r) = -1;
  else (*f)++;
  return data;
}

char peek(char *queue, int f, int r)
{
  if (isEmpty(queue, f, r)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  return queue[f];
}

void display(char *queue, int f, int r)
{
  if (isEmpty(queue, f, r)) {
    printf("Queue is Empty\n");
    return;
  }
  for (int i = f; i <= r; i++) printf("%c ", queue[i]);
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
        enqueue(queue, &f, &r, data);
        display(queue, f, r);
        break;

      case 2:
        data = dequeue(queue, &f, &r);
        if (data) printf("%c has been processed\n", data);
        display(queue, f, r);
        break;

      case 3:
        data = peek(queue, f, r);
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
