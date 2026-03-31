#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initStack(Stack *s);
void pushStack(Stack *s, int data);
int popStack(Stack *s);
int peekStack(Stack *s);
int isStackEmpty(Stack *s);
void displayStack(Stack *s);
void freeStack(Stack *s);

int main() {
    Stack s;
    initStack(&s);

    int choice, data;
    int cont = 1;

    printf("Linked Stack Operations:\n");
    printf("1. Push   2. Pop   3. Peek   4. Display   5. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &data);
                pushStack(&s, data);
                break;
            case 2:
                if ((data = popStack(&s)) != -1)
                    printf("Popped value: %d\n", data);
                break;
            case 3:
                if ((data = peekStack(&s)) != -1)
                    printf("Top element: %d\n", data);
                break;
            case 4:
                displayStack(&s);
                break;
            case 5:
                cont = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    freeStack(&s);
    return 0;
}

void initStack(Stack *s) {
    s->top = NULL;
}

int isStackEmpty(Stack *s) {
    return s->top == NULL;
}

void pushStack(Stack *s, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed %d to stack\n", data);
}

int popStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }

    Node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

int peekStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}

void displayStack(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    Node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeStack(Stack *s) {
    while (!isStackEmpty(s))
        popStack(s);
}
