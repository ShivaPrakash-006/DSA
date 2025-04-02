#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int isEmpty(char *s, int top) { return top == -1; }

int isFull(char *s, int top) { return top == MAX - 1; }

void push(char *s, int *top, char v) {
  if (!isFull(s, *top)) {
    (*top)++;
    s[*top] = v;
  }
}

char pop(char *s, int *top) {
  if (isEmpty(s, *top))
    return '\0';
  char v = s[*top];
  (*top)--;
  return v;
}

char peek(char *s, int top) {
  if (isEmpty(s, top))
    return '\0';
  else
    return s[top];
}

int isOpenBrack(char sym) { return (sym == '(' || sym == '[' || sym == '{'); }

int isCloseBrack(char sym) { return (sym == ')' || sym == ']' || sym == '}'); }

int isOperator(char sym) {
  return (sym == '+' || sym == '-' || sym == '/' || sym == '*' || sym == '$');
}

int isp(char op) {
  if (op == '$')
    return 4;
  else if (op == '/' || op == '*')
    return 3;
  else if (op == '+' || op == '-')
    return 2;
  return 0;
}

int icp(char op) {
  if (op == '$')
    return 5;
  else if (op == '/' || op == '*')
    return 3;
  else if (op == '+' || op == '-')
    return 2;
  return 0;
}

int prec(char op1, char op2) { return (isp(op1) >= icp(op2)); }

void inToPost(char *exp, char *res) {
  char s[100] = {};
  int top = -1;

  for (int i = 0; i < strlen(exp); i++) {
    if (isalpha(exp[i]))
      res[strlen(res)] = exp[i];
    else if (isOpenBrack(exp[i]))
      push(s, &top, exp[i]);
    else if (isCloseBrack(exp[i])) {
      while (!isOpenBrack(peek(s, top)))
        res[strlen(res)] = pop(s, &top);
      pop(s, &top);
    } else if (isOperator(exp[i])) {
      while (!isEmpty(s, top) && !isOpenBrack(peek(s, top)) &&
             prec(peek(s, top), exp[i]))
        res[strlen(res)] = pop(s, &top);
      push(s, &top, exp[i]);
    }
  }

  while (!isEmpty(s, top))
    res[strlen(res)] = pop(s, &top);
}

int main() {
  char exp[100] = {};
  char res[100] = {};
  scanf("%s", exp);
  inToPost(exp, res);
  printf("%s\n", res);

  return 0;
}
