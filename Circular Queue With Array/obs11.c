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

void enqueue(char *queue, int *front, int *rear, char data)
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

char dequeue(char *queue, int *front, int *rear)
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

char peek(char *queue, int front, int rear)
{
  if (isEmpty(queue, front, rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  return queue[front];
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
        enqueue(queue, &front, &rear, data);
        break;

      case 2:
        data = dequeue(queue, &front, &rear);
        if (data) printf("%c has been processed\n", data);
        break;

      case 3:
        data = peek(queue, front, rear);
        if (data) printf("%c is in the front\n", data);
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
