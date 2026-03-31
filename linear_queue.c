#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int size);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int frontElement(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {
    Queue q;
    initQueue(&q, MAX_SIZE);

    int choice, value;
    int cont = 1;

    printf("Queue Operations:\n");
    printf("1. Insert  2. Delete  3. Front  4. Display  5. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                if ((value = dequeue(&q)) != -1)
                    printf("Deleted value: %d\n", value);
                break;
            case 3:
                if ((value = frontElement(&q)) != -1)
                    printf("Front element: %d\n", value);
                break;
            case 4:
                displayQueue(&q);
                break;
            case 5:
                cont = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    freeQueue(&q);
    return 0;
}

void initQueue(Queue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    q->front = q->rear = -1;
    q->capacity = size;
}

int isFull(Queue *q) {
    return q->rear == q->capacity - 1;
}

int isEmpty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear++;

    q->arr[q->rear] = value;
    printf("Inserted %d into queue\n", value);
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return value;
}

int frontElement(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void freeQueue(Queue *q) {
    free(q->arr);
}
