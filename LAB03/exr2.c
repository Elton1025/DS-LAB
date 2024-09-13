#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int num) {
    s->data[++s->top] = num;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

void decimalToBase(int decimal, int base, Stack s) {
    while (decimal > 0) {
        push(&s, decimal % base);
        decimal /= base;
    }
    printf("The decimal number in base %d is: ", base);
    while (s.top >= 0) {
        int digit = pop(&s);
        if (digit <=9) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + digit - 10);
        }
    }
    printf("\n");
}

int main() {
    int decimal, base;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    printf("Enter the base to convert to: ");
    scanf("%d", &base);

    Stack s;
    s.top = -1;

    decimalToBase(decimal, base, s);
    return 0;
}
