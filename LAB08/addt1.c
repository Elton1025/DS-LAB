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

struct Node* unionList(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* result = NULL;
    struct Node* t1 = list1, *t2 = list2;

    // Insert all elements of list1 in result
    while (t1 != NULL) {
        insertAtRear(&result, t1->data);
        t1 = t1->next;
    }

    // Insert those elements of list2 that are not present in result
    while (t2 != NULL) {
        struct Node* current = result;
        int found = 0;
        while (current != NULL) {
            if (current->data == t2->data) {
                found = 1;
                break;
            }
            current = current->next;
        }
        if (!found) {
            insertAtRear(&result, t2->data);
        }
        t2 = t2->next;
    }
    return result;
}

struct Node* intersectionList(struct Node* list1, struct Node* list2) {
    if (list1 == NULL || list2 == NULL)
        return NULL;

    struct Node* result = NULL;
    struct Node* t1 = list1;

    while (t1 != NULL) {
        struct Node* t2 = list2;
        while (t2 != NULL) {
            if (t1->data == t2->data) {
                insertAtRear(&result, t1->data);
                break;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return result;
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

    struct Node* unionResult = unionList(X1, X2);
    printf("Union of X1 and X2: ");
    traverse(unionResult);

    struct Node* intersectionResult = intersectionList(X1, X2);
    printf("Intersection of X1 and X2: ");
    traverse(intersectionResult);

    return 0;
}
