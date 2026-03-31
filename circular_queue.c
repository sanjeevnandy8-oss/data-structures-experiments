#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int *arr;
    int front;
    int rear;
    int count;
    int capacity;
} CircularQueue;

void initCircularQueue(CircularQueue *cq, int size);
int isFull(CircularQueue *cq);
int isEmpty(CircularQueue *cq);
void enqueueCQ(CircularQueue *cq, int value);
int dequeueCQ(CircularQueue *cq);
int frontCQ(CircularQueue *cq);
void displayCQ(CircularQueue *cq);
void freeCircularQueue(CircularQueue *cq);

int main() {
    CircularQueue cq;
    initCircularQueue(&cq, MAX_SIZE);

    int choice, value;
    int cont = 1;

    printf("Circular Queue Operations:\n");
    printf("1. Insert  2. Delete  3. Front  4. Display  5. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueueCQ(&cq, value);
                break;
            case 2:
                if ((value = dequeueCQ(&cq)) != -1)
                    printf("Deleted value: %d\n", value);
                break;
            case 3:
                if ((value = frontCQ(&cq)) != -1)
                    printf("Front element: %d\n", value);
                break;
            case 4:
                displayCQ(&cq);
                break;
            case 5:
                cont = 0;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    freeCircularQueue(&cq);
    return 0;
}

void initCircularQueue(CircularQueue *cq, int size) {
    cq->arr = (int *)malloc(size * sizeof(int));
    cq->front = 0;
    cq->rear = -1;
    cq->count = 0;
    cq->capacity = size;
}

int isFull(CircularQueue *cq) {
    return cq->count == cq->capacity;
}

int isEmpty(CircularQueue *cq) {
    return cq->count == 0;
}

void enqueueCQ(CircularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Circular queue is full!\n");
        return;
    }

    cq->rear = (cq->rear + 1) % cq->capacity;
    cq->arr[cq->rear] = value;
    cq->count++;
    printf("Inserted %d into circular queue\n", value);
}

int dequeueCQ(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty!\n");
        return -1;
    }

    int value = cq->arr[cq->front];
    cq->front = (cq->front + 1) % cq->capacity;
    cq->count--;
    return value;
}

int frontCQ(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty!\n");
        return -1;
    }
    return cq->arr[cq->front];
}

void displayCQ(CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty!\n");
        return;
    }

    printf("Circular queue elements: ");
    int i = cq->front;
    for (int j = 0; j < cq->count; j++) {
        printf("%d ", cq->arr[i]);
        i = (i + 1) % cq->capacity;
    }
    printf("\n");
}

void freeCircularQueue(CircularQueue *cq) {
    free(cq->arr);
}
