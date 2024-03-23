#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 3

int stack[n];
int top = -1;
void push()
{
    if (top == n - 1)
    {
        printf("stack is full\n");
    }
    else
    {
        int x;
        printf("Enter value to be pushed into the stack \n");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}
int peek()
{
    int x = stack[top];
    printf("The value at top of stack is : %d\n", x);
    return x;
}
int pop()
{
    int x = stack[top];
    if (top == -1)
    {
        printf("Please enter any data in stack \n");
    }
    else
    {
        int x = stack[top];
        printf("value poped is : %d \n", x);
        top = top - 1;
        return x;
    }
    return -1;
}
bool isfull()
{
    if (top == n - 1)
    {
        printf("Stack is full \n");
        return true;
    }
    else
    {
        printf("stack is not full\n");
        return false;
    }
}
bool isEmpty()
{
    if (top == -1)
    {
        printf("Stack is empty \n");
        return true;
    }
    else
    {
        printf("stack has some data\n");
        return false;
    }
}
int main()
{
    printf("Stack Capacity is : %d\n", n);
    int data;
    while (1)
    {
        printf("Choose any of the following options:\n");
        printf("Press 1 to Push \n");
        printf("Press 2 to Peek \n");
        printf("Press 3 to Pop \n");
        printf("Press 4 to stack is full\n");
        printf("Press 5 to stack is empty\n");
        printf("Press 6 to Exit \n");
        scanf("%d", &data);
        switch (data)
        {
        case 1:
            push();
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:
            isfull();
            break;
        case 5:
            isEmpty();
            break;
        case 6:
            printf("Program Exit");
            exit(0);
            break;
        default:
            printf("Please Choose a value between 1 to 6\n");
            break;
        }
    }
    return 0;
}