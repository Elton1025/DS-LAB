#include<stdio.h>

#define SIZE 10

struct Stack {
    char items[SIZE];
    int top;

};

int lent(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}
_Bool isFull(struct Stack *palin) {
    return palin->top== SIZE - 1;
}

void push(struct Stack *palin,char item) {
    if(isFull(palin)) {
        printf("Stack Overflow, cannot push %d\n",item);
        return;
    }
    palin->top++;
    palin->items[palin->top]=item;

}

void initialize(struct Stack *palin) {
    palin->top=-1;

}

_Bool isEmpty(struct Stack *palin) {
    return palin->top ==-1;
}

int pop(struct Stack *palin) {
    if(isEmpty(palin)) {
        printf("Stack Underflow\n");
        return -1;
    }
    char popped = palin->items[palin->top];
    palin->top--;
    return popped;

}

char peek(struct Stack *palin) {
    if(isEmpty(palin)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return palin->items[palin->top];

}
int palindrome(struct Stack palin) {
    int flag=1;
    int k=palin.top;
    for(int i=0;i<lent(palin.items);i++) {
        while(i<=k) {
            if(palin.items[i]!=palin.items[k]) {
                flag=0;
                return flag;
            }
            k--;
        }
    }
    return flag;

}

int main() {
    struct Stack palin;
    initialize(&palin);

    int ch,i;
    char item[SIZE];
    while(1) {
        printf("\nStack Menu\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Palindrome\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch) {
        case 1:
            printf("Enter the item to push:");
            scanf("%s",item);
            push(&palin,item);
            break;


        case 2:
            i = pop(&palin);
            if(item!=-1)
                printf("Popped item %s\n",item);
            break;
        case 3:
            i= pop(&palin);
            if(i != -1)
                printf("top item %s\n",item);
            break;

        case 4:
            if(palindrome(palin)==1) {
                printf("Stack is Palindrome!");
            }
            else {
                printf("Stack is not a palindrome");
            }

        case 5:
            printf("Exit...\n");
            return 0;
        default:
            printf("Invalid Choice, Enter valid choice:\n");
        }
    }

}
