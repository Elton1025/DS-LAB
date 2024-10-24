#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct Node* addTwoLists(struct Node* first, struct Node* second) {
    struct Node* res = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);

        if (res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first) first = first->next;
        if (second) second = second->next;
    }

    if (carry > 0)
        temp->next = newNode(carry);

    return res;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
    char num1[100], num2[100];

    printf("Enter first number: ");
    scanf("%s", num1);
    printf("Enter second number: ");
    scanf("%s", num2);

    int len1 = strlen(num1);
    for (int i = len1 - 1; i >= 0; i--)
        push(&first, num1[i] - '0');

    int len2 = strlen(num2);
    for (int i = len2 - 1; i >= 0; i--)
        push(&second, num2[i] - '0');

    res = addTwoLists(first, second);

    printf("Resultant list is: ");
    printList(res);

    return 0;
}
