#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

void insert(struct Queue *queue, int input)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = input;
    newNode->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Input Inserted");
}

void delete(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue has no values\n");
    }
    else
    {
        struct Node *temp = queue->front;
        queue->front = queue->front->next;
        printf("Front element Deleted: %d", temp->data);
        free(temp);
    }
}

void display(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue has no values");
    }
    else
    {
        struct Node *temp = queue->front;
        while (temp != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}

int main()
{
    struct Queue queue = {NULL, NULL};
    int choice, input;

    printf("\nImplementation of queue using Linked List");
    while (1)
    {
        printf("\nChoose from available options");
        printf("\n1.Insert \n2.Delete \n3.Display \n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the input: ");
            scanf("%d", &input);
            insert(&queue, input);
            break;
        case 2:
            delete (&queue);
            break;
        case 3:
            display(&queue);
            break;
        case 4:
            exit(0);
        default:
            printf("\nPlease choose from available options");
        }
    }
    return 0;
}
