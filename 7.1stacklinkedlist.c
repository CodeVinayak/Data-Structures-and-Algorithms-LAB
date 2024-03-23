#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int);
void pop();
void display();

int main()
{
    int choice, value;
    printf("\nImplementation of Stack using LinkedList");
    while (1)
    {
        printf("\nChoose from available options");
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the input: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nPlease choose from available options");
        }
    }
    return 0;
}

void push(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (top == NULL)
        newNode->next = NULL;
    else
        newNode->next = top;

    top = newNode;
    printf("Input Inserted");
}

void pop()
{
    if (top == NULL)
        printf("Stack has no value\n");
    else
    {
        struct Node *temp = top;
        printf("Last element Deleted %d", temp->data);
        top = temp->next;
        free(temp);
    }
}

void display()
{
    if (top == NULL)
        printf("Stack has no value\n");
    else
    {
        struct Node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL", temp->data);
    }
}
