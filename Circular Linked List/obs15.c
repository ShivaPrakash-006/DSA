#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* getNode() {
  return (Node*) malloc(sizeof(Node));
}

void display(Node *head, Node *tail)
{
  Node *temp = head;
  while (temp != tail) {
    printf("%i ", temp->data);
    temp = temp->next;
  }
  if (temp != NULL)
    printf("%i", temp->data);
  printf("\n");
}

void insert(Node **head, Node **tail, int data, int pos)
{
  Node *new = getNode();
  new->data = data;

  if (*head == NULL) {
    *head = *tail = new;
    (*head)->next = *tail;
  }

  else if (pos == 0) { //Beginning
    new->next = *head;
    *head = new;
    (*tail)->next = *head;
  }

  else if (pos == -1) { //End
    new->next = *head;
    (*tail)->next = new;
    *tail = new;
  }

  else if (pos > 0) { //Middle
    Node *temp = *head;
    int i = 1;
    while (i < pos && temp->next != NULL) {
      temp = temp->next;
      i++;
    }
    new->next = temp->next;
    temp->next = new;
  }
}

void delete(Node **head, Node **tail, int pos)
{
  if (*head == NULL) {
    printf("Empty List\n");
    return;
  }

  if (*head == *tail) {
    free(*head);
    *head = *tail = NULL;
  }

  else if (pos == 0) {
    Node *toFree = *head;
    *head = (*head)->next;
    (*tail)->next = *head;
    free(toFree);
  }

  else if (pos == -1) {
    Node *temp = *head;
    while (temp->next != *tail)
      temp = temp->next;
    free(*tail);
    *tail = temp;
    (*tail)->next = *head;
  }

  else if (pos > 0) { //Middle
    Node *temp = *head;
    int i = 1;
    while (i < pos && temp->next->next != NULL) {
      temp = temp->next;
      i++;
    }
    Node *toFree = temp->next;
    temp->next = temp->next->next;
    free(toFree);
  }
}

int search(Node *head, Node *tail, int data) 
{
  Node *temp = head;
  int i = 0;
  while (temp != tail) {
    if (temp->data == data)
      return i;
    temp = temp->next;
    i++;
  }
  if (temp != NULL && temp->data == data)
    return i;
  return -1;
}

int main(){
  Node *head = NULL, *tail = NULL;
  int data, pos, choice = 0;

  while (choice != 5) {
    printf("1. Insert\n2. Delete\n3. Display\n4. Search\n5. Exit\nEnter Your Choice: ");
    scanf("%i", &choice); printf("\n");

    switch (choice) {
      case 1:
        printf("Enter Data: "); scanf("%i", &data);
        printf("Enter Position (0->Beg, -1->End): "); scanf("%i", &pos);
        if (pos < -1)
          printf("Invalid Position\n");
        insert(&head, &tail, data, pos);
        display(head, tail);
        break;

      case 2:
        printf("Enter Position (0->Beg, -1->End): "); scanf("%i", &pos);
        if (pos < -1)
          printf("Invalid Position\n");
        delete(&head, &tail, pos);
        display(head, tail);
        break;

      case 3:
        display(head, tail);
        break;

      case 4:
        printf("Enter Data: "); scanf("%i", &data);
        pos = search(head, tail, data);
        if (pos != -1)
          printf("%i is at position %i\n", data, pos);
        else
          printf("Data not found\n");
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
