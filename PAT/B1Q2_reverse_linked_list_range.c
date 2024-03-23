/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Aim:
To reverse a portion of a singly linked list, specified by the positions 'left' and 'right', and return the modified linked list.

Algorithm: Reverse a Portion of Singly Linked List
1.Initialize Linked List:
    Create a singly linked list with nodes containing integer values.
2.Initialize Parameters:
    Set the head of the linked list to the given head.
    Set the values of 'left' and 'right' representing the range to be reversed.
3.Create a Dummy Node:
    Create a dummy node to simplify edge cases, and set it to point to the head of the linked list.
4.Move to the Node Before Reversal:
    Traverse the list to the node just before the reversal starts ('left' position).
5.Reverse the Nodes:
    Initialize pointers for the reversal: 'current', 'next', and 'tail'.
    Reverse the nodes from 'left' to 'right':
        Use a loop to reverse the pointers of each node.
        Connect the reversed portion back to the original list.
6.Print the Modified List:
    In the main function, print the original linked list.
    Call the 'reverseBetween' function to reverse the specified portion.
    Print the modified linked list.
*/
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse a portion of a linked list from position left to position right.
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) {
        return head;
    }

    // Create a dummy node to simplify edge cases.
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    // Move to the node just before the reversal.
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Reverse the nodes from left to right.
    struct ListNode* current = prev->next;
    struct ListNode* next = NULL;
    struct ListNode* tail = current;

    for (int i = left; i <= right; i++) {
        struct ListNode* temp = current->next;
        current->next = next;
        next = current;
        current = temp;
    }

    // Connect the reversed portion back to the original list.
    prev->next = next;
    tail->next = current;

    return dummy.next;
}

// Function to print the linked list.
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example usage
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int left = 2, right = 4;

    printf("Original List: ");
    printList(head);

    head = reverseBetween(head, left, right);

    printf("Reversed List from position %d to %d: ", left, right);
    printList(head);

    return 0;
}
