#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char data;
  struct Node *next;
} Node;

Node *getNode() { return (Node *)malloc(sizeof(Node)); }

void display(Node *top) {
  Node *temp = top;
  printf("Top -> ");
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void push(Node **top, char data) {
  Node *new = getNode();
  new->data = data;
  new->next = *top;
  *top = new;
}

char pop(Node **top) {
  if (*top == NULL)
    return '\0';

  char data = (*top)->data;
  Node *toFree = *top;
  *top = (*top)->next;
  free(toFree);

  return data;
}

char peek(Node *top) {
  if (top == NULL)
    return '\0';
  else
    return top->data;
}

int main() {
  Node *top = NULL;
  int choice = 0;
  char data = '\0';

  while (choice != 5) {
    printf(
        "1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nEnter Your Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data: ");
      scanf("\n%c", &data);
      push(&top, data);
      display(top);
      break;

    case 2:
      data = pop(&top);
      if (data) {
        printf("%c was popped\n", data);
        display(top);
      } else
        printf("Empty Stack\n");
      break;

    case 3:
      display(top);
      break;

    case 4:
      data = peek(top);
      if (data)
        printf("%c -> Top\n", peek(top));
      else
        printf("Empty Stack\n");
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
