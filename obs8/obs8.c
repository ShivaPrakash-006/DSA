#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

int isEmpty(float *s, int top)
{
    return top == -1;
}

int isFull(float *s, int top)
{
    return top == MAX-1;
}

void push(float *s, int *top, float v)
{
    if (!isFull(s, *top))
    {
        (*top)++;
        s[*top] = v;
    }
}

float pop(float *s, int *top)
{
    if (isEmpty(s, *top))
        return 0;
    return s[(*top)--];
}

float ctof(char num)
{
    return (float) (num - 48);
}

int isOperator(char sym)
{
    return (sym == '+' || sym == '-' || sym == '/' || sym == '*' || sym == '$');
}

float operate(float op1, float op2, char op)
{
    switch (op)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': if (op2 == 0) return 0; else return op1 / op2;
        case '$': return pow(op1, op2);
    }
}

float prefixEval(const char *exp)
{
    float stack[MAX] = {};
    int top = -1;
    for (int i = strlen(exp); i > -1 ; i--)
    {
        if (isdigit(exp[i]))
            push(stack, &top, ctof(exp[i]));
        else if (isOperator(exp[i])) {
            float op1 = pop(stack, &top);
            float op2 = pop(stack, &top);
            float val = operate(op1, op2, exp[i]);
            push(stack, &top, val);
        }
    }
    return pop(stack, &top);
}
//--+AB/*+CDEF$AB
int main (int argc, char *argv[]) {
    char exp[MAX] = {};
    scanf("%s", exp);
    float val = prefixEval(exp);
    printf("%f", val);

    return 0;
}