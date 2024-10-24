#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *prev;
    struct Node *next;
};

struct Node* newNode(int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->prev = new_node->next = NULL;
    return new_node;
}

struct Node* createHeaderNode() {
    struct Node* header = newNode(0, 0);
    header->prev = header->next = header;
    return header;
}

void insert(struct Node* header, int coeff, int exp) {
    struct Node* new_node = newNode(coeff, exp);
    struct Node* last = header->prev;

    new_node->next = header;
    header->prev = new_node;
    new_node->prev = last;
    last->next = new_node;
}

void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node* result) {
    struct Node *p1 = poly1->next, *p2 = poly2->next;

    while (p1 != poly1 && p2 != poly2) {
        if (p1->exp == p2->exp) {
            insert(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            insert(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            insert(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != poly1) {
        insert(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != poly2) {
        insert(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
}

void printPolynomial(struct Node* header) {
    struct Node* temp = header->next;
    if (temp == header) {
        printf("0\n");
        return;
    }
    while (temp != header) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != header) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = createHeaderNode();
    struct Node *poly2 = createHeaderNode();
    struct Node *result = createHeaderNode();
    int n, coeff, exp;

    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(poly1, coeff, exp);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    addPolynomials(poly1, poly2, result);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
