#include <stdio.h>
#define MAX 6

typedef struct Data {
  char value;
  int priority;
} Data;

int isFull(Data *queue, int front, int rear)
{
  return rear == MAX-1;
}

int isEmpty(Data *queue, int front, int rear)
{
  return front == -1;
}

void enqueue(Data *queue, int *front, int *rear, Data data)
{
  if (isFull(queue, *front, *rear)) {
    printf("Queue is Full\n");
    return;
  }
  if (isEmpty(queue, *front, *rear)) (*rear) = (*front) = 0;
  else (*rear)++;
  queue[*rear] = data;
}

char dequeue(Data *queue, int *front, int *rear)
{
  if (isEmpty(queue, *front, *rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  
  int pos = 0;
  int min = queue[pos].priority;
  char data = queue[pos].value;

  if ((*front) == (*rear)) {
    (*front) = (*rear) = -1;
    return data;
  }

  for (int i = 1; i <= *rear; i++)
    if (queue[i].priority < min) {
      pos = i;
      min = queue[i].priority;
      data = queue[i].value;
    }

  for (int i = pos; i < *rear; i++)
    queue[i] = queue[i+1];
  
  (*rear)--;
  return data;
}

char peek(Data *queue, int front, int rear)
{
  if (isEmpty(queue, front, rear)) {
    printf("Queue is Empty\n");
    return '\0';
  }
  int min = queue[0].priority;
  char data = queue[0].value;

  for (int i = 1; i <= rear; i++)
    if (queue[i].priority < min) {
      min = queue[i].priority;
      data = queue[i].value;
    }
  return data;
}

void display(Data *queue, int front, int rear)
{
  if (isEmpty(queue, front, rear)) {
    printf("Queue is Empty\n");
    return;
  }
  for (int i = front; i <= rear; i++) printf("%c|%i ", queue[i].value, queue[i].priority);
  printf("\n");
}

int main()
{
  int choice = 0, rear = -1, front = -1;
  char value = '\0';
  Data data = {'\0', 0};

  Data queue[MAX] = {};

  while (choice != 5) {
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter Your Choice: ");
    scanf("%i", &choice); printf("\n");

    switch (choice) {
      case 1:
        printf("Enter Data: ");
        do data.value = getchar(); while (data.value == '\n' || data.value == '\0');
        printf("Enter Priority: ");
        scanf("%i", &data.priority);
        enqueue(queue, &front, &rear, data);
        display(queue, front, rear);
        break;

      case 2:
        value = dequeue(queue, &front, &rear);
        if (value) printf("%c has been processed\n", value);
        display(queue, front, rear);
        break;

      case 3:
        value = peek(queue, front, rear);
        if (value) printf("%c is in the front\n", value);
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
