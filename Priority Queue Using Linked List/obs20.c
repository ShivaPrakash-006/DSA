#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  int priority;
  struct Node *next;
} Node;

Node *getNode() { return (Node *)malloc(sizeof(Node)); }

void display(Node *front) {
  Node *temp = front;
  printf("Front -> ");
  while (temp != NULL) {
    printf("%c|%i ", temp->data, temp->priority);
    temp = temp->next;
  }
  printf("\n");
}

void enqueue(Node **front, char data, int priority) {
  Node *new = getNode();
  new->data = data;
  new->priority = priority;
  new->next = NULL;

  if (*front == NULL)
    *front = new;

  else if ((*front)->priority > priority) {
    new->next = *front;
    *front = new;

  } else {
    Node *temp = *front;
    while (temp->next != NULL) {
      if (priority < temp->next->priority)
        break;
      temp = temp->next;
    }
    new->next = temp->next;
    temp->next = new;
  }
}

char dequeue(Node **front) {
  if (*front == NULL)
    return '\0';
  else {
    char data = (*front)->data;
    Node *toFree = *front;
    *front = (*front)->next;
    free(toFree);
    return data;
  }
}

char peek(Node *front) {
  if (front == NULL)
    return '\0';
  else
    return front->data;
}

int main() {
  Node *front = NULL;
  int choice = 0, priority = 0;
  char data = '\0';

  while (choice != 5) {
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter Your "
           "Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data & Priority (d p): ");
      scanf("\n%c %i", &data, &priority);
      enqueue(&front, data, priority);
      display(front);
      break;

    case 2:
      data = dequeue(&front);
      if (data) {
        printf("%c has been Dequeued\n", data);
        display(front);
      } else
        printf("Empty Queue\n");
      break;

    case 3:
      display(front);
      break;

    case 4:
      data = peek(front);
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
