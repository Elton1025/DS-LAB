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

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* SortedMerge(struct Node* a, struct Node* b) {
    struct Node* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    } else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

int main() {
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;
    int n, data;

    printf("Enter the number of nodes for list A: ");
    scanf("%d", &n);
    printf("Enter the nodes in non-decreasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&a, data);
    }

    printf("Enter the number of nodes for list B: ");
    scanf("%d", &n);
    printf("Enter the nodes in non-decreasing order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&b, data);
    }

    printf("List A: ");
    printList(a);
    printf("List B: ");
    printList(b);

    res = SortedMerge(a, b);

    printf("Merged Linked List: ");
    printList(res);

    return 0;
}
