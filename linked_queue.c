#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initQueue(Queue *q);
void enqueueQueue(Queue *q, int data);
int dequeueQueue(Queue *q);
int frontQueue(Queue *q);
int isQueueEmpty(Queue *q);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {
    Queue q;
    initQueue(&q);

    int choice, data;
    int cont = 1;

    printf("Linked Queue Operations:\n");
    printf("1. Enqueue   2. Dequeue   3. Front   4. Display   5. Exit\n");

    while (cont) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueueQueue(&q, data);
                break;
            case 2:
                if ((data = dequeueQueue(&q)) != -1)
                    printf("Dequeued value: %d\n", data);
                break;
            case 3:
                if ((data = frontQueue(&q)) != -1)
                    printf("Front element: %d\n", data);
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

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isQueueEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueueQueue(Queue *q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isQueueEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued %d into queue\n", data);
}

int dequeueQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

int frontQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->data;
}

void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(Queue *q) {
    while (!isQueueEmpty(q))
        dequeueQueue(q);
}
