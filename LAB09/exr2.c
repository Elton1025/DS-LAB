#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* newNode(int coeff, int exp) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    return new_node;
}

void insert(struct Node** head_ref, int coeff, int exp) {
    struct Node* new_node = newNode(coeff, exp);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

void addPolynomials(struct Node* poly1, struct Node* poly2, struct Node** result) {
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
}

void printPolynomial(struct Node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&poly1, coeff, exp);
    }

    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &n);
    printf("Enter the coefficient and exponent of each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insert(&poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);

    addPolynomials(poly1, poly2, &result);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
