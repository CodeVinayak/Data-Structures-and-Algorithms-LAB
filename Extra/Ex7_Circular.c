#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertBegin(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    
    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;

    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertPosition(int item, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;

    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
    } else {
        struct node* temp = head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
            if (temp == head) {
                printf("Position out of range\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteElement(int item) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* current = head;
    struct node* prev = NULL;

    while (1) {
        if (current->data == item) {
            if (prev == NULL) {
                struct node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                if (temp == head) {
                    head = NULL;
                    free(temp);
                } else {
                    temp->next = head->next;
                    free(head);
                    head = temp->next;
                }
            } else {
                prev->next = current->next;
                if (current == head) {
                    head = prev->next;
                }
                free(current);
            }
            printf("Element %d deleted\n", item);
            return;
        }

        prev = current;
        current = current->next;
        if (current == head) {
            break; 
        }
    }

    printf("Element %d not found in the list\n", item);
}

void display() {
    if (head == NULL) {
        printf("List has no value\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, item, position;

    while (1) {
        printf("\nChoose from given option:\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at a Position\n");
        printf("4. Delete Element\n");
        printf("5. Display Elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insertBegin(item);
                break;

            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insertEnd(item);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertPosition(item, position);
                break;

            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &item);
                deleteElement(item);
                break;

            case 5:
                printf("Elements in the list: ");
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please choose from available options\n");
        }
    }

    return 0;
}