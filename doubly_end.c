#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data);
void insertAtEnd(Node **head, int data);
void deleteLastNode(Node **head);
void displayForward(Node *head);
void displayBackward(Node *head);
void freeList(Node *head);

int main() {
    Node *head = NULL;

    int choice, data;
    int cont = 1;

    printf("Doubly Linked List Operations:\n");
    printf("1. Insert at end   2. Delete last   3. Display forward   4. Display backward   5. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                deleteLastNode(&head);
                break;
            case 3:
                displayForward(head);
                break;
            case 4:
                displayBackward(head);
                break;
            case 5:
                cont = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    freeList(head);
    return 0;
}

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end\n", data);
}

void deleteLastNode(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("Deleted %d from list\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted %d from list\n", temp->data);
    free(temp);
}

void displayForward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List (forward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayBackward(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (head->next != NULL)
        head = head->next;

    printf("List (backward): ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

void freeList(Node *head) {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}
