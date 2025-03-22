#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node *next;
} Node;

Node *getNode() { return (Node *)malloc(sizeof(Node)); }

void display(Node *front, Node *rear) {
  Node *temp = front;
  printf("Front -> ");
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("<- Rear\n");
}

void enqueue(Node **front, Node **rear, char data) {
  Node *new = getNode();
  new->data = data;
  new->next = NULL;

  if (*rear == NULL)
    *front = *rear = new;

  else {
    (*rear)->next = new;
    *rear = new;
  }
}

char dequeue(Node **front, Node **rear) {
  if (*front == NULL)
    return '\0';
  char data = (*front)->data;
  Node *toFree = *front;
  if (*front == *rear)
    *front = *rear = NULL;
  else
    *front = (*front)->next;
  free(toFree);
  return data;
}

char peek(Node *front, Node *rear) {
  if (front == NULL)
    return '\0';
  else
    return front->data;
}

int main() {
  Node *front = NULL, *rear = NULL;
  int choice = 0;
  char data = '\0';

  while (choice != 5) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter Your "
           "Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data: ");
      scanf("\n%c", &data);
      enqueue(&front, &rear, data);
      display(front, rear);
      break;

    case 2:
      data = dequeue(&front, &rear);
      if (data) {
        printf("%c Dequeued\n", data);
        display(front, rear);
      } else
        printf("Empty Queue\n");
      break;

    case 3:
      display(front, rear);
      break;

    case 4:
      data = peek(front, rear);
      if (data)
        printf("%c -> Front\n", data);
      else
        printf("Empty Queue\n");
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
