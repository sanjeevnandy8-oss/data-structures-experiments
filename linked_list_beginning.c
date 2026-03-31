#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void insertAtBeginning(Node **head, int data);
void deleteFirstNode(Node **head);
void displayList(Node *head);
void freeList(Node *head);

int main() {
    Node *head = NULL;

    int choice, data;
    int cont = 1;

    printf("Linked List Operations:\n");
    printf("1. Insert at beginning   2. Delete first   3. Display   4. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                deleteFirstNode(&head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
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
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at beginning\n", data);
}

void deleteFirstNode(Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from list\n", temp->data);
    free(temp);
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
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
