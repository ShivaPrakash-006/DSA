#include <stdio.h>

int isEmpty(char *s, int top) { return top == -1; }

int isFull(char *s, int top) { return top == 99; }

void push(char *s, int *top, char v) {
  if (isFull(s, *top)) {
    printf("Overflow!\n");
    return;
  }
  (*top)++;
  s[*top] = v;
}

char pop(char *s, int *top) {
  if (isEmpty(s, *top)) {
    printf("Underflow!\n");
    return '\0';
  }
  char v = s[*top];
  (*top)--;
  return v;
}

char peek(char *s, int top) {
  if (isEmpty(s, top))
    return '\0';
  return s[top];
}

void display(char *s, int top) {
  for (int i = top; i > -1; i--)
    printf("%c\n", s[i]);
}

int main() {
  int choice = 0;
  char data = '\0';

  char s[100] = {};
  int top = -1;

  while (choice != 5) {
    printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter Your Choice: ");
    scanf("%i", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      printf("Enter Data: ");

      do
        data = getchar();
      while (data == '\n' || data == '\0');
      push(s, &top, data);
      printf("Stack has %i elements. %c is the top element\n", top + 1,
             peek(s, top));
      break;

    case 2:
      data = pop(s, &top);
      if (data)
        printf("%c has been popped\n", data);

      if (isEmpty(s, top))
        printf("Stack is Empty\n");
      else
        printf("Stack has %i elements. %c is the top element\n", top + 1,
               peek(s, top));
      break;

    case 3:
      if (isEmpty(s, top))
        printf("Stack is Empty\n");
      else
        printf("Stack has %i elements. %c is the top element\n", top + 1,
               peek(s, top));
      break;

    case 4:
      if (isEmpty(s, top))
        printf("Stack is Empty\n");
      else
        display(s, top);
      break;

    case 5:
      printf("Bye Bye!\n");
      break;

    default:
      printf("Invalid Choice!\n");
    }
    printf("\n");
  }

  return 0;
}
