#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert the sum of consecutive elements in the linked list
void insertSum(struct Node* head) {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        // Calculate the sum of consecutive elements
        int sum = current->data + current->next->data;

        // Create a new node with the sum
        struct Node* newNode = createNode(sum);

        // Insert the new node between the current node and the next node
        newNode->next = current->next;
        current->next = newNode;

        // Move to the next pair of consecutive elements
        current = current->next->next;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Create the sample linked list: 12 -> 34 -> 56 -> 78 -> 15
    struct Node* head = createNode(12);
    head->next = createNode(34);
    head->next->next = createNode(56);
    head->next->next->next = createNode(78);
    head->next->next->next->next = createNode(15);

    // Insert the sum of consecutive elements
    insertSum(head);

    // Print the modified linked list
    printf("Modified Linked List: ");
    printList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
