#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a person
struct Person {
    char name[50];
};

// Structure to implement a queue
struct Queue {
    struct Person* data;
    int front;
    int rear;
    int capacity;
};

// Function to create a new queue
struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->data = (struct Person*)malloc(sizeof(struct Person) * capacity);
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

// Function to enqueue a person into the queue
void enqueue(struct Queue* queue, const char* name) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %s\n", name);
        return;
    }
    
    struct Person newPerson;
    strcpy(newPerson.name, name);
    
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    
    queue->data[queue->rear] = newPerson;
}

// Function to dequeue a person from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    
    printf("%s took the printout first.\n", queue->data[queue->front].name);
    
    if (queue->front == queue->rear) {
        // If there was only one person in the queue, reset the queue
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % queue->capacity;
    }
}

int main() {
    struct Queue* printQueue = createQueue(4); // Assuming there are 4 people in the queue

    // Enqueue the people in the specified order
    enqueue(printQueue, "Ravi");
    enqueue(printQueue, "Sam");
    enqueue(printQueue, "Ahamed");
    enqueue(printQueue, "Abraham");

    // Dequeue the person who took the printout first
    dequeue(printQueue);

    free(printQueue->data);
    free(printQueue);

    return 0;
}
