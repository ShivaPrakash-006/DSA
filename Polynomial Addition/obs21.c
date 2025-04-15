#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int coeff;
  int expo;
  struct Node *next;
} Node;

Node *getNode() { return (Node *)malloc(sizeof(Node)); }

void insert(Node **head, Node *term) {
  if (*head == NULL) {
    term->next = NULL;
    *head = term;
  } else if ((*head)->expo < term->expo) {
    term->next = *head;
    *head = term;
  } else {
    Node *temp = *head;
    while (temp->next != NULL && term->expo > temp->next->expo)
      temp = temp->next;
    term->next = temp->next;
    temp->next = term;
  }
}

Node *create() {
  Node *head = NULL;
  int coeff, expo, n;
  printf("Enter Number Of Terms: ");
  scanf("%i", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter Term %i (cxe): ", i + 1);
    scanf("%ix%i", &coeff, &expo);
    Node *newTerm = getNode();
    newTerm->coeff = coeff;
    newTerm->expo = expo;
    insert(&head, newTerm);
  }
  return head;
}

Node *add(Node *poly1, Node *poly2) {
  Node *temp1 = poly1, *temp2 = poly2;
  Node *poly3 = NULL;
  while (temp1 != NULL && temp2 != NULL) {
    Node *term = getNode();
    if (temp1->expo == temp2->expo) {
      term->coeff = temp1->coeff + temp2->coeff;
      term->expo = temp1->expo;
      temp1 = temp1->next;
      temp2 = temp2->next;
    } else if (temp1->expo < temp2->expo) {
      term->coeff = temp2->coeff;
      term->expo = temp2->expo;
      temp2 = temp2->next;
    } else {
      term->coeff = temp1->coeff;
      term->expo = temp1->expo;
      temp1 = temp1->next;
    }
    insert(&poly3, term);
  }
  while (temp1 != NULL) {
    Node *term = getNode();
    term->coeff = temp1->coeff;
    term->expo = temp1->expo;
    temp1 = temp1->next;
    insert(&poly3, term);
  }
  while (temp2 != NULL) {
    Node *term = getNode();
    term->coeff = temp2->coeff;
    term->expo = temp2->expo;
    temp2 = temp2->next;
    insert(&poly3, term);
  }
  return poly3;
}

void display(Node *poly) {
  Node *temp = poly;
  while (temp->next != NULL) {
    printf("%ix%i + ", temp->coeff, temp->expo);
    temp = temp->next;
  }
  printf("%ix%i\n", temp->coeff, temp->expo);
}

int main() {
  Node *poly1 = create();
  display(poly1);
  Node *poly2 = create();
  display(poly2);
  Node *poly3 = add(poly1, poly2);
  display(poly3);
  return 0;
}
