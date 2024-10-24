#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Stack {
    struct Node *top;
};

struct Stack* createStack() {
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}


void push(struct Stack *stack, int data) {
    struct Node* new_node = newNode(data);
    new_node->next = stack->top;
    stack->top = new_node;
    printf("%d pushed to stack\n", data);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}


struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isQueueEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q, int data) {
    struct Node* new_node = newNode(data);

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
    printf("%d enqueued to queue\n", data);
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node* temp = q->front;
    int dequeued = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return dequeued;
}

void displayQueue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    struct Stack *stack = createStack();
    struct Queue *q = createQueue();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Peek Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                printf("%d popped from stack\n", pop(stack));
                break;
            case 3:
                printf("Top element is %d\n", peek(stack));
                break;
            case 4:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 5:
                printf("%d dequeued from queue\n", dequeue(q));
                break;
            case 6:
                displayQueue(q);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
