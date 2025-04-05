#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *create(void) {
  int x;
  scanf("%i", &x);
  if (x == -1)
    return NULL;
  Node *ptr = (Node *)malloc(sizeof(Node));
  ptr->data = x;
  printf("Left of %i: ", x);
  ptr->left = create();
  printf("Right of %i: ", x);
  ptr->right = create();
  return ptr;
}

void inOrder(Node *root) {
  if (root == NULL)
    return;
  inOrder(root->left);
  printf("%i ", root->data);
  inOrder(root->right);
}

void postOrder(Node *root) {
  if (root == NULL)
    return;
  postOrder(root->left);
  postOrder(root->right);
  printf("%i ", root->data);
}

void preOrder(Node *root) {
  if (root == NULL)
    return;
  printf("%i ", root->data);
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  printf("Root: ");
  Node *root = create();
  printf("In Order Traversal: ");
  inOrder(root);
  printf("\nPre Order Traversal: ");
  preOrder(root);
  printf("\nPost Order Traversal: ");
  postOrder(root);
  printf("\n");

  return 0;
}
