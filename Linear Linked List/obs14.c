#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* getNode() {
  return (Node*) malloc(sizeof(Node));
}

void display(Node *head)
{
  Node *temp = head;
  while (temp != NULL) {
    printf("%i ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void insert(Node **head, int data, int pos)
{
  Node *new = getNode();
  new->data = data;
  new->next = NULL;

  if (*head == NULL) { //If Empty
    *head = new;
  }

  else if (pos == 0) { //Insert Beginning
    new->next = *head;
    *head = new;
  }

  else if (pos == -1) { //Insert End
    Node *temp = *head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = new;
  }

  else if (pos > 0) { //Insert Middle
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

void delete(Node **head, int pos)
{
  if (*head == NULL) { //Empty
    printf("Empty List\n");
    return; 
  }
  
  else if (pos == 0) { //Delete Beginning
    Node *toFree = *head;
    *head = (*head)->next;
    free(toFree);
  }

  else if (pos == -1) { //Delete End
    Node *temp = *head;
    while (temp->next->next != NULL)
      temp = temp->next;
    free(temp->next);
    temp->next = NULL;
  }

  else { //Delete Middle
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

int search(Node *head, int data)
{
  Node *temp = head;
  int i = 0;
  while (temp != NULL) {
    if (temp->data == data)
      return i; //Found
    temp = temp->next;
    i++;
  }

  return -1; //Not Found
}

int main(){
  Node *head = NULL;
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
        insert(&head, data, pos);
        display(head);
        break;

      case 2:
        printf("Enter Position (0->Beg, -1->End): "); scanf("%i", &pos);
        if (pos < -1)
          printf("Invalid Position\n");
        delete(&head, pos);
        display(head);
        break;

      case 3:
        display(head);
        break;

      case 4:
        printf("Enter Data: "); scanf("%i", &data);
        pos = search(head, data);
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
