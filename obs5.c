#include <stdio.h>
#include <string.h>

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

int main()
{
    int choice = 0;
    char data = '\0';

    char s[100] = {};
    int top = -1;

    while (choice != 5)
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Exit")
    }

    return 0;
}
