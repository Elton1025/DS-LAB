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

void insert(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);

    if (*head_ref == NULL) {
        new_node->next = new_node->prev = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* last = (*head_ref)->prev;

    new_node->next = *head_ref;
    (*head_ref)->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;

    struct Node *current = *head_ref, *prev;

    // If the list has only one node
    if (current->next == current && current->data == key) {
        free(current);
        *head_ref = NULL;
        return;
    }

    // Find the node to be deleted
    while (current->data != key) {
        if (current->next == *head_ref) {
            printf("Given node is not found in the list!!!\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    // If the node to be deleted is the first node
    if (current == *head_ref) {
        prev = (*head_ref)->prev;
        *head_ref = current->next;
        prev->next = *head_ref;
        (*head_ref)->prev = prev;
        free(current);
        return;
    }

    // Change the pointers of the adjacent nodes
    prev->next = current->next;
    current->next->prev = prev;
    free(current);
}

void traverse(struct Node* head) {
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
