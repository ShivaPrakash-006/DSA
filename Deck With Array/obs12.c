#include <stdio.h>
#define MAX 3

int isFull(char *queue, int front, int rear)
{
  return ((front == rear + 1) || (rear == MAX - 1 && front == 0));
}

int isEmpty(char *queue, int front, int rear)
{
  return front == -1;
}

void insertFront(char *queue, int *front, int *rear, char data)
{
  if (isFull(queue, *front, *rear)) {
    printf("Queue is Full\n");
    return;
  }
  if (isEmpty(queue, *front, *rear)) (*rear) = (*front) = 0;
  else if ((*front) == 0) (*front) = MAX - 1;
  else (*front)--;
  queue[*front] = data;
}

void insertRear(char *queue, int *front, int *rear, char data)
{
  if (isFull(queue, *front, *rear)) {
    printf("Queue is Full\n");
    return;
  }
  if (isEmpty(queue, *front, *rear)) (*rear) = (*front) = 0;
  else if ((*rear) == MAX - 1) (*rear) = 0;
  else (*rear)++;
  queue[*rear] = data;
}

char deleteFront(char *queue, int *front, int *rear)
{
  if (isEmpty(queue, *front, *rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  char data = queue[*front];
  if ((*front) == (*rear)) (*front) = (*rear) = -1;
  else if ((*front) == MAX - 1) (*front) = 0;
  else (*front)++;
  return data;
}

char deleteRear(char *queue, int *front, int *rear)
{
  if (isEmpty(queue, *front, *rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  char data = queue[*rear];
  if ((*front) == (*rear)) (*front) = (*rear) = -1;
  else if ((*rear) == 0) (*rear) = MAX - 1;
  else (*rear)--;
  return data;
}

char peekFront(char *queue, int front, int rear)
{
  if (isEmpty(queue, front, rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  return queue[front];
}

char peekRear(char *queue, int front, int rear)
{
  if (isEmpty(queue, front, rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  return queue[rear];
}

void display(char *queue, int front, int rear)
{
  if (isEmpty(queue, front, rear)) {
    printf("Queue is Empty\n");
    return;
  }
  if (front <= rear) for (int i = front; i <= rear; i++) printf("%c ", queue[i]);
  else {
    for (int i = front; i < MAX; i++) printf("%c ", queue[i]);
    for (int i = 0; i <= rear; i++) printf("%c ", queue[i]);
  }
  printf("\n");
}

int main()
{
  int choice = 0, rear = -1, front = -1;
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
            insertFront(queue, &front, &rear, data);
            break;

          case 2:
            insertRear(queue, &front, &rear, data);
            break;

          default:
            printf("Invalid Choice\n");
        }
        break;

      case 2:
        printf("1. Front\n2. Rear\nEnter Your Choice: ");
        scanf("%i", &choice);

        switch (choice) {
          case 1:
            data = deleteFront(queue, &front, &rear);
            break;

          case 2:
            data = deleteRear(queue, &front, &rear);
            break;

          default:
            printf("Invalid Choice\n");
            data = '\0';
        }

        if (data) printf("%c has been processed\n", data);
        break;

      case 3:
        data = peekFront(queue, front, rear);
        if (data) printf("%c is in the front\n", data);

        data = peekRear(queue, front, rear);
        if (data) printf("%c is in the rear\n", data);
        break;

      case 4:
        display(queue, front, rear);
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
