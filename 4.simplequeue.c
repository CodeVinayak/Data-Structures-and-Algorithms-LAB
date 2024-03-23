#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main() {
    int queue[MAX_SIZE];
    int choice = 1;
    int front = 0;
    int rear = 0;
    int i;
    int capacity = MAX_SIZE;

    printf("Queue Implementation using Array\n");
    printf("Choose from the options:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");

    while (choice) {
        printf("\nPlease Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (rear == capacity)
                    printf("\nQueue is Full");
                else {
                    printf("\nEnter input: ");
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if (front == rear) {
                    printf("\nQueue is empty");
                } else {
                    printf("\nDeleted Element: %d", queue[front++]);
                    capacity++;
                }
                break;
            case 3:
                printf("\nQueue Elements are:\n");
                if (front == rear)
                    printf("\nQueue is Empty");
                else {
                    for (i = front; i < rear; i++) {
                        printf("%d", queue[i]);
                        printf("\n");
                    }
                    break;
                }
            case 4:
                printf("Program Exit\n");
                exit(0);
            default:
                printf("Please enter valid options");
        }
    }
    return 0;
}
