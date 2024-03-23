#include <stdio.h>
#include <stdlib.h>
#define n 4

int queue[n];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if ((rear + 1) % n == front)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % n;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % n;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = front;
        printf("Queue is: ");
        while (1)
        {
            printf("%d ", queue[i]);
            if (i == rear)
                break;
            i = (i + 1) % n;
        }
        printf("\n");
    }
}

int main()
{
    int num, input;
    do
    {
        printf("Choose from any option:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your input : ");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &input);
            enqueue(input);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid Input\n");
        }
    } while (num != 4);

    return 0;
}
