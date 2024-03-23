/*
Given the head of a linked list, remove the nth node from the end of the list and return its headGiven the head of a linked list, remove the nth node from the end of the list and return its head
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:
Input: head = [1], n = 1
Output: []
Example 3:
Input: head = [1,2], n = 1
Output: [1]

Aim:
To remove the nth node from the end of a linked list and return the modified linked list.

Algorithm:
1.Initialize Linked List:
	Create a singly linked list with nodes containing integer values.
2.Initialize Parameters:
	Set the head of the linked list to the given head.
	Set the value of 'n' representing the position from the end to be removed.
3.Create a Dummy Node:
	Create a dummy node to simplify edge cases, and set it to point to the head of the linked list.
4.Initialize Pointers:
	Initialize two pointers, 'first' and 'second', both pointing to the dummy node.
5.Move First Pointer to (n + 1)th Node:
	Use a loop to move the 'first' pointer to the (n + 1)th node in the linked list.
6.Move Both Pointers Until End:
	Move both pointers ('first' and 'second') until the 'first' pointer reaches the end of the linked list.
	The 'second' pointer will now be pointing to the node just before the nth node from the end.
7.Remove Nth Node:
	Update the 'next' pointer of the 'second' node to skip the nth node.
8.Free Memory:
	Free the memory allocated for the removed node.
9.Return Modified List:
	Return the modified linked list.
10.Print the Modified List:
	In the main function, print the original linked list.
	Call the 'nthnode' function to remove the specified node.
	Print the modified linked list.
*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int val;
	struct ListNode* next;
};
struct ListNode* nthnode(struct ListNode* head, int n)
{
	struct ListNode* mynode = (struct ListNode*)malloc(sizeof(struct ListNode));
	mynode->next = head;
	struct ListNode* first = mynode;
	struct ListNode* second = mynode;

	for (int i = 0; i < n + 1; i++) {
	first = first->next;
	}
while (first != NULL)
	{
	first = first->next;
	second = second->next;
	}
	struct ListNode* temp = second->next;
	second->next = second->next->next;
	free(temp);
	return mynode->next;
}

	struct ListNode* createNode(int val)
	{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->val = val;
	newnode->next = NULL;
	return newnode;
	}
	void printList(struct ListNode* head)
{
	struct ListNode* current = head;
	while (current != NULL)
	{
	printf("%d -> ", current->val);
	current = current->next;
	}
	printf("NULL\n");
}

int main()
{
	struct ListNode* head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	int n = 2;
	head = nthnode(head, n);
	printList(head);
	return 0;
}
