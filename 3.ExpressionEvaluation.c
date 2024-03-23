#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is overflow\n");
        return;
    }
    stack[++top] = value;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack is underflow\n");
        return -1;
    }
    return stack[top--];
}
int evaluatePostfix(char *expression)
{
    for (int i = 0; expression[i]; i++)
    {
        if (isdigit(expression[i]))
        {
            push(expression[i] - '0');
        }
        else
        {
            int num2 = pop();
            int num1 = pop();
            switch (expression[i])
            {
            case '+':
                push(num1 + num2);
                break;
            case '-':
                push(num1 - num2);
                break;
            case '*':
                push(num1 * num2);
                break;
            case '/':
                push(num1 / num2);
                break;
                return -1;
            }
        }
    }
    return pop();
}
int main()
{
    char expression[] = "10+2*";
    int result = evaluatePostfix(expression);

    if (result != -1)
    {
        printf("Result is : %d\n", result);
    }
    return 0;
}