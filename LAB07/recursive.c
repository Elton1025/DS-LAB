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

struct Node* createLinkedListRecursive() {
    int data;
    printf("Enter data (or -1 to stop): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* head = newNode(data);
    head->next = createLinkedListRecursive();
    return head;
}

void traverseRecursive(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printf("%d ", head->data);
    traverseRecursive(head->next);
}

int main() {
    struct Node* head = NULL;

    printf("Create Linked List:\n");
    head = createLinkedListRecursive();

    printf("Linked List: ");
    traverseRecursive(head);
    printf("\n");

    return 0;
}
