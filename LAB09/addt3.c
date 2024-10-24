#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int time;
    struct Customer *prev;
    struct Customer *next;
};

struct Customer* newCustomer(char *name, int time) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy(new_customer->name, name);
    new_customer->time = time;
    new_customer->prev = new_customer->next = NULL;
    return new_customer;
}

struct Customer* createList() {
    struct Customer* header = newCustomer("", 0);
    header->prev = header->next = header;
    return header;
}

void enqueue(struct Customer* header, char *name, int time) {
    struct Customer* new_customer = newCustomer(name, time);
    struct Customer* last = header->prev;

    new_customer->next = header;
    header->prev = new_customer;
    new_customer->prev = last;
    last->next = new_customer;

    printf("Customer %s added to the queue.\n", name);
}

void dequeue(struct Customer* header) {
    if (header->next == header) {
        printf("Queue is empty.\n");
        return;
    }

    struct Customer* first = header->next;
    header->next = first->next;
    first->next->prev = header;

    printf("Customer %s has finished using the washing machine.\n", first->name);
    free(first);
}

void displayQueue(struct Customer* header) {
    if (header->next == header) {
        printf("Queue is empty.\n");
        return;
    }

    struct Customer* temp = header->next;
    printf("Current queue:\n");
    while (temp != header) {
        printf("-> %s (%d min) ", temp->name, temp->time);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Customer* header = createList();
    char name[50];
    int time, choice;

    while (1) {
        printf("\nWashing Machine Renting System\n");
        printf("1. Book Washing Machine\n");
        printf("2. Finish Using Washing Machine\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter renting time (in minutes): ");
                scanf("%d", &time);
                enqueue(header, name, time);
                break;
            case 2:
                dequeue(header);
                break;
            case 3:
                displayQueue(header);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
