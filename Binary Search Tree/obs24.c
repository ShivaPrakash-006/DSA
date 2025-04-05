#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *getNewNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  return newNode;
}

Node *insert(Node *root, int data) {
  if (root == NULL)
    root = getNewNode(data);
  else if (data <= root->data)
    root->left = insert(root->left, data);
  else
    root->right = insert(root->right, data);
  return root;
}

int search(Node *root, int data) {
  if (root == NULL)
    return 0;
  else if (data == root->data)
    return 1;
  else if (data < root->data)
    return search(root->left, data);
  else
    return search(root->right, data);
}

Node *min(Node *root) {
  if (root == NULL)
    return NULL;
  else if (root->left == NULL)
    return root;
  else
    return min(root->left);
}

Node *max(Node *root) {
  if (root == NULL)
    return NULL;
  else if (root->right == NULL)
    return root;
  else
    return min(root->right);
}

Node *delete(Node *root, int data) {
  if (root == NULL)
    printf("Element Not Found!\n");
  else if (data < root->data)
    root->left = delete (root->left, data);
  else if (data > root->data)
    root->right = delete (root->right, data);
  else {
    if (root->right == NULL && root->left == NULL) {
      Node *temp = root;
      root = NULL;
      free(temp);
    } else if (root->left == NULL) {
      Node *temp = root;
      root = root->left;
      free(temp);
    } else if (root->right == NULL) {
      Node *temp = root;
      root = root->right;
      free(temp);
    } else {
      Node *temp = min(root->right);
      root->data = temp->data;
      root->right = delete (root->right, temp->data);
    }
    return root;
  }
  return root;
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
  int data, choice = 0;
  Node *root = NULL;

  while (choice != 5) {
    printf("1. Insert\n2. Traverse\n3. Search\n4. Delete\n5. Exit\nEnter Your "
           "Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data: ");
      scanf("%i", &data);
      root = insert(root, data);
      break;

    case 2:
      printf("1. PreOrder\n2. InOrder\n3. PostOrder\nEnter Your Choice: ");
      scanf("%i", &choice);
      switch (choice) {
      case 1:
        preOrder(root);
        break;
      case 2:
        inOrder(root);
        break;
      case 3:
        preOrder(root);
        break;
      }
      printf("\n");
      break;

    case 3:
      printf("Enter Data: ");
      scanf("%i", &data);
      if (search(root, data))
        printf("%i exists in tree\n", data);
      else
        printf("%i is not in the tree\n", data);
      break;

    case 4:
      printf("Enter Data: ");
      scanf("%i", &data);
      delete (root, data);
      break;

    case 5:
      printf("Bye Bye!\n");
      break;

    default:
      printf("Invalid Choice\n");
    }
    printf("\n");
  }
}
