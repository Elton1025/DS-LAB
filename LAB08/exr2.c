#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

void insertAtRear(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

void traverse(struct Node* head) {
    struct Node* last;
    printf("Traversal in forward direction \n");
    while (head != NULL) {
        printf(" %d ", head->data);
        last = head;
        head = head->next;
    }
    printf("\n");
}

void concatenate(struct Node** X1, struct Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
        return;
    }

    if (X2 == NULL) {
        return;
    }

    struct Node* temp = *X1;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = X2;
    X2->prev = temp;
}

int main() {
    struct Node* X1 = NULL;
    struct Node* X2 = NULL;
    int n, data;

    printf("Enter the number of nodes for list X1: ");
    scanf("%d", &n);
    printf("Enter the nodes for list X1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtRear(&X1, data);
    }

    printf("Enter the number of nodes for list X2: ");
    scanf("%d", &n);
    printf("Enter the nodes for list X2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertAtRear(&X2, data);
    }

    printf("List X1: ");
    traverse(X1);
    printf("List X2: ");
    traverse(X2);

    concatenate(&X1, X2);

    printf("Concatenated List X1: ");
    traverse(X1);

    return 0;
}
