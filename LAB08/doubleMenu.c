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

void deleteAtRear(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    free(last);
}

void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    struct Node* new_node = newNode(new_data);

    if (position == 1) {
        new_node->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = new_node;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
}

void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        printf("List is empty or invalid position\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (position == 1) {
        *head_ref = temp->next;
        if (*head_ref != NULL)
            (*head_ref)->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = newNode(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data) {
    if (next_node == NULL) {
        printf("The given next node cannot be NULL\n");
        return;
    }

    struct Node* new_node = newNode(new_data);
    new_node->prev = next_node->prev;
    next_node->prev = new_node;
    new_node->next = next_node;
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        *head_ref = new_node;
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

void reverse(struct Node** head_ref) {
    struct Node* temp = NULL;
    struct Node* current = *head_ref;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head_ref = temp->prev;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at rear\n");
        printf("2. Delete at rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Insert after\n");
        printf("6. Insert before\n");
        printf("7. Traverse\n");
        printf("8. Reverse\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtRear(&head, data);
                break;
            case 2:
                deleteAtRear(&head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the data after which to insert: ");
                int afterData;
                scanf("%d", &afterData);
                struct Node *temp = head;
                while (temp != NULL && temp->data != afterData) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Element not found.\n");
                } else {
                    insertAfter(temp, data);
                }
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the data before which to insert: ");
                int beforeData;
                scanf("%d", &beforeData);
                temp = head;
                while (temp != NULL && temp->data != beforeData) {
                    temp = temp->next;
                }
                if (temp == NULL) {
                    printf("Element not found.\n");
                } else {
                    insertBefore(&head, temp, data);
                }
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                reverse(&head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
