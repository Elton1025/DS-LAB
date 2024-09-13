#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;

// Function to create a new circular queue
void initializeQueue(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    if ((q->front == 0 && q->rear == MAX - 1) || (q->rear == (q->front - 1) % (MAX - 1))) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to insert an element in the queue
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1) { // First element being added
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

// Function to remove an element from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = q->items[q->front];
    q->items[q->front] = -1;

    if (q->front == q->rear) { // The queue is now empty
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    printf("Deleted %d\n", data);
    return data;
}

// Function to display the queue
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->items[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->items[i]);
}

// Main function
int main() {
    CircularQueue q;
    initializeQueue(&q);
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                displayQueue(&q);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
