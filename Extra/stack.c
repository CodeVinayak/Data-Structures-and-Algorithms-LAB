// Program to demonstrate the various operations on array based stack
#include <stdio.h>
#include <stdlib.h>
#define Max 20
typedef struct
{
    int top;
    int elements[Max];
} stack;
typedef enum
{
    false,
    true
} boolean;
// create an Empty Stack
void createStack(stack *ps)
{
    ps->top = -1;
}
// testing if stack for underflow
boolean isEmpty(stack *ps)
{
    if (ps->top == -1)
        return true;
    else
        return false;
}
// testing stack for overflow
boolean isFull(stack *ps)
{
    if (ps->top == (Max - 1))
        return true;
    else
        return false;
}
// Push operation
void push(stack *ps, int value)
{
    ps->top++;
    ps->elements[ps->top] = value;
}
// Pop operation
int pop(stack *ps)
{
    int temp;
    temp = ps->elements[ps->top];
    ps->top--;
    return temp;
}
// Accessing top element
int peek(stack *ps)
{
    return (ps->elements[ps->top]);
}
void main()
{
    int choice, element;
    stack s;
    createStack(&s);
    do
    {
        printf("Options available \n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Peek \n");
        printf("4.Exit \n");
        printf("ENTER your choice between (1-4) :\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&s))
            {
                printf("stack is full,press any key to continue \n");
            }
            else
            {
                printf("Enter Value : ");
                scanf("%d", &element);
                push(&s, element);
            }
            break;
        case 2:
            if (isEmpty(&s))
            {
                printf("stack empty,press any key to continue \n");
            }
            else
            {
                printf("value poped is %d \n", pop(&s));
                printf("Press any key to continue \n");
            }
            break;
        case 3:
            if (isEmpty(&s))
            {
                printf("stack empty,press any key to continue \n");
            }
            else
            {
                printf("value at top is %d \n", peek(&s));
                printf("Press any key to continue ....\n");
            }
        }
      
    }  while (choice != 4);
}