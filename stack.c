#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int top;
    int capacity;
} Stack;

void initStack(Stack *s, int size);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void displayStack(Stack *s);
void freeStack(Stack *s);

int main() {
    Stack s;
    initStack(&s, MAX_SIZE);

    int choice, value;
    int cont = 1;

    printf("Stack Operations:\n");
    printf("1. Push   2. Pop   3. Peek   4. Display   5. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&s, value);
                break;
            case 2:
                if ((value = pop(&s)) != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                if ((value = peek(&s)) != -1)
                    printf("Top element: %d\n", value);
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

void initStack(Stack *s, int size) {
    s->arr = (int *)malloc(size * sizeof(int));
    s->top = -1;
    s->capacity = size;
}

int isFull(Stack *s) {
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = value;
    printf("Pushed %d to stack\n", value);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

void freeStack(Stack *s) {
    free(s->arr);
}
