/*
You’re given the pointer to the head nodes of two linked lists. Compare the data in the nodes of the linked lists to check if they are equal. If all data attributes are equal and the lists are the same length, return . Otherwise, return 0.
Example
The two lists have equal data attributes for the first  nodes.  is longer, though, so the lists are not equal. Return .

Aim:
To compare the data in the nodes of two linked lists and determine if they are equal. Return if all data attributes are equal and the lists are the same length; otherwise, return 0.

Algorithm:
1.Initialize Pointers:
    Set two pointers, head1 and head2, to the heads of the two linked lists.
2.Traverse Both Lists:
    Use a loop to traverse both linked lists simultaneously.
    Compare the data attribute of each node in the linked lists.
3.Check for Equality:
    If the data attributes of all nodes are equal and both lists have the same length, return .
    If any data attribute is not equal or the lengths of the lists differ, return .
4.Return Result:
    If the loop completes without returning, it indicates that all nodes are equal, and the lists have the same length. Return .
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to compare two linked lists
int compareLists(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        // Compare data attributes of nodes
        if (head1->data != head2->data) {
            return 0; // Not equal
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Check if both lists have the same length
    if (head1 == NULL && head2 == NULL) {
        return 1; // Equal
    } else {
        return 0; // Not equal
    }
}

// Example usage in the main function
int main() {
    // Example linked lists
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));

    // Initialize linked lists with data
    head1->data = 1;
    head1->next = (struct Node*)malloc(sizeof(struct Node));
    head1->next->data = 2;
    head1->next->data = 4;
    head1->next->data = 5;
    head1->next->next = NULL;

    head2->data = 1;
    head2->next = (struct Node*)malloc(sizeof(struct Node));
    head2->next->data = 2;
    head2->next->data = 4;
    head2->next->data = 5;
    head2->next->next = NULL;

    // Compare linked lists and print the result
    if (compareLists(head1, head2)) {
        printf("Linked lists are equal.\n");
    } else {
        printf("Linked lists are not equal.\n");
    }

    return 0;
}
