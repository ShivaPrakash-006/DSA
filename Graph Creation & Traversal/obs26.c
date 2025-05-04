#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void push(Node **stk, int data) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = *stk;
  *stk = new;
}

int pop(Node **stk) {
  if (*stk == NULL)
    return -1;
  Node *toFree = *stk;
  *stk = (*stk)->next;
  int data = toFree->data;
  free(toFree);
  return data;
}

void enqueue(Node **front, Node **rear, int data) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;

  if (*rear == NULL)
    *front = *rear = new;

  else {
    (*rear)->next = new;
    *rear = new;
  }
}

int dequeue(Node **front, Node **rear) {
  if (*front == NULL)
    return -1;
  int data = (*front)->data;
  Node *toFree = *front;
  if (*front == *rear)
    *front = *rear = NULL;
  else
    *front = (*front)->next;
  free(toFree);
  return data;
}

void DFS(int **graph, int n) {
  Node *stk = NULL;
  int visited[n] = {};
  push(&stk, 0);
  while (stk != NULL) {
    int node = pop(&stk);
    if (visited[node] == 0) {
      printf("%i ", node);
      visited[node] = 1;
    }
    for (int i = 0; i < n; i++)
      if (graph[node][i] == 1 && visited[i] != 1)
        push(&stk, i);
  }
  printf("\n");
}

void BFS(int **graph, int n) {
  Node *front = NULL, *rear = NULL;
  int visited[n] = {};
  enqueue(&front, &rear, 0);
  printf("%i ", 0);
  visited[0] = 1;
  while (front != NULL) {
    int node = dequeue(&front, &rear);
    for (int i = 0; i < n; i++)
      if (graph[node][i] == 1 && visited[i] != 1) {
        enqueue(&front, &rear, i);
        printf("%i ", i);
        visited[i] = 1;
      }
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter Number of Vertices: ");
  scanf("%i", &n);
  int **graph = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    graph[i] = (int *)malloc(n * sizeof(int));
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int choice = 0;
      printf("Link %i to %i (1/0)? ", i, j);
      scanf("%i", &choice);
      if (choice == 0) {
        graph[i][j] = 0;
        graph[j][i] = 0;
      } else {
        graph[i][j] = 1;
        graph[j][i] = 1;
      }
    }
  }
  printf("DFS: ");
  DFS(graph, n);
  printf("BFS: ");
  BFS(graph, n);

  return 0;
}
