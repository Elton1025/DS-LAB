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

struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* head = list1;
    struct Node* current1 = list1;
    struct Node* current2 = list2;
    struct Node* next1;

    while (current1 != NULL && current2 != NULL) {
        next1 = current1->next;
        current1->next = current2;
        current2 = current2->next;
        current1->next->next = next1;
        current1 = next1;
    }

    return head;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* list3 = NULL;
    int n, m, data;


    printf("Enter the number of nodes for list1: ");
    scanf("%d", &n);
    printf("Enter the nodes for list1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&list1, data);
    }


    printf("Enter the number of nodes for list2: ");
    scanf("%d", &m);
    printf("Enter the nodes for list2:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        push(&list2, data);
    }

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);


    list3 = mergeLists(list1, list2);

    printf("Merged Linked List: ");
    printList(list3);

    return 0;
}
