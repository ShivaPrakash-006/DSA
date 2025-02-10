#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isEmpty(char *s, int top)
{
  if (top == -1)
    return 1;
  else
    return 0;
}

int isFull(char *s, int top)
{
  if (top == 99)
    return 1;
  else
    return 0;
}

void push(char *s, int *top, char v)
{
  if (!isFull(s, *top)) {
    (*top)++;
    s[*top] = v;
  }
}

char pop(char *s, int *top)
{
  if (isEmpty(s, *top))
    return '\0';
  char v = s[*top];
  (*top)--;
  return v;
}

char peek(char *s, int top)
{
  return s[top];
}

int isOpenBrack(char sym)
{
  if (sym == '(' || sym == '[' || sym == '{')
    return 1;
  else
    return 0;
}

int isCloseBrack(char sym)
{
  if (sym == ')' || sym == ']' || sym == '}')
    return 1;
  else
    return 0;
}

int isOperator(char sym)
{
  if (sym == '+' || sym == '-' || sym == '/' || sym == '*' || sym == '$')
    return 1;
  else
    return 0;
}

int isp(char op)
{
  if (op == '$')
    return 4;
  else if (op == '/' || op == '*')
    return 3;
  else if (op == '+' || op == '-')
    return 2;
}

int icp(char op)
{
  if (op == '$')
    return 5;
  else if (op == '/' || op == '*')
    return 3;
  else if (op == '+' || op == '-')
    return 2;
}

int prec(char op1, char op2)
{
  if (isp(op1) > icp(op2))
    return 1;
  else
    return 0;
}

void strrev(char *str)
{
  int i = 0;
  int j = strlen(str) - 1;

  while (i<j) {
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
    i++;
    j--;
  }
}

void inToPre(char *exp, char *res)
{
  char s[100] = {};
  int top = -1;

  for (int i = strlen(exp) - 1; i >= 0; i--)
  {
    if (isalpha(exp[i]))
      res[strlen(res)] = exp[i];
    else if (isCloseBrack(exp[i]))
      push(s, &top, exp[i]);
    else if (isOpenBrack(exp[i])) {
      while (!isCloseBrack(peek(s, top)))
        res[strlen(res)] = pop(s, &top);
      pop(s, &top);
    }
    else if (isOperator(exp[i])) {
      while (!isEmpty(s, top) && !isCloseBrack(peek(s, top)) && prec(peek(s, top), exp[i]))
        res[strlen(res)] = pop(s, &top);
      push(s, &top, exp[i]);
    }
  }
  
  while (!isEmpty(s, top))
    res[strlen(res)] = pop(s, &top);

  strrev(res);
}

int main()
{
  char exp[100] = {};
  char res[100] = {};
  scanf("%s", exp);
  inToPre(exp, res);
  printf("%s", res);

  return 0;
}
