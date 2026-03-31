#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void insertAtLocation(Node **head, int data, int position);
void searchNode(Node *head, int data);
void displayList(Node *head);
void freeList(Node *head);

int main() {
    Node *head = NULL;

    int choice, data, position;
    int cont = 1;

    printf("Linked List Operations:\n");
    printf("1. Insert at location   2. Search   3. Display   4. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                printf("Enter position (0-based): ");
                scanf("%d", &position);
                insertAtLocation(&head, data, position);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &data);
                searchNode(head, data);
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

void insertAtLocation(Node **head, int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }

    Node *newNode = createNode(data);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *temp = *head;
        int i = 0;

        while (temp != NULL && i < position - 1) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Position out of range!\n");
            free(newNode);
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d at position %d\n", data, position);
}

void searchNode(Node *head, int data) {
    int position = 0;
    while (head != NULL) {
        if (head->data == data) {
            printf("Found %d at position %d\n", data, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("%d not found in list\n", data);
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
