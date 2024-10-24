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

void insertBefore(struct Node** head_ref, int new_data, int existing_data) {
    struct Node* new_node = newNode(new_data);

    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head_ref)->data == existing_data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    while (current->next != NULL && current->next->data != existing_data) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found.\n");
    } else {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void sort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct Node *end_node = NULL;
    while (end_node != head) {
        struct Node *current = head;
        while (current->next != end_node) {
            struct Node *next_node = current->next;
            if (current->data > next_node->data) {
                int temp = current->data;
                current->data = next_node->data;
                next_node->data = temp;
            }
            current = current->next;
        }
        end_node = current;
    }
}

void deleteAlternate(struct Node *head) {
    if (head == NULL) {
        return;
    }

    struct Node *current = head;
    while (current != NULL && current->next != NULL) {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}

void insertSorted(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);

    if (*head_ref == NULL || data < (*head_ref)->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* current = *head_ref;
    while (current->next != NULL && data > current->next->data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}


int main() {
    struct Node* head = NULL;
    int choice, new_data, existing_data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert before\n");
        printf("2. Insert after\n");
        printf("3. Delete node\n");
        printf("4. Traverse\n");
        printf("5. Reverse\n");
        printf("6. Sort\n");
        printf("7. Delete alternate\n");
        printf("8. Insert in sorted list\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &new_data);
                printf("Enter existing data: ");
                scanf("%d", &existing_data);
                insertBefore(&head, new_data, existing_data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &new_data);
                printf("Enter existing data: ");
                scanf("%d", &existing_data);

                struct Node *temp = head;
                while (temp != NULL && temp->data != existing_data) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Element not found.\n");
                } else {
                    insertAfter(temp, new_data);
                }
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &new_data);
                deleteNode(&head, new_data);
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                reverse(&head);
                break;
            case 6:
                sort(head);
                break;
            case 7:
                deleteAlternate(head);
                break;
            case 8:
                printf("Enter data to insert: ");
                scanf("%d", &new_data);
                insertSorted(&head, new_data);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
