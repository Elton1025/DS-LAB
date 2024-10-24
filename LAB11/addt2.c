#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
  char data;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

struct Node* createExpressionTree(char postfix[]) {
  struct Node *stack[100];
  int top = -1;
  for (int i = 0; postfix[i]; ++i) {
    if (isdigit(postfix[i])) {
      stack[++top] = newNode(postfix[i]);
    } else {
      struct Node *t1 = stack[top--];
      struct Node *t2 = stack[top--];
      struct Node *temp = newNode(postfix[i]);
      temp->right = t1;
      temp->left = t2;
      stack[++top] = temp;
    }
  }
  return stack[top];
}

int eval(struct Node* root) {
  if (!root) {
    return 0;
  }
  if (!root->left && !root->right) {
    return root->data - '0';
  }
  int l_val = eval(root->left);
  int r_val = eval(root->right);
  switch (root->data) {
    case '+': return l_val + r_val;
    case '-': return l_val - r_val;
    case '*': return l_val * r_val;
    case '/': return l_val / r_val;
  }
  return 0;
}

int main() {
  char postfix[100];
  printf("Enter postfix expression: ");
  scanf("%s", postfix);

  struct Node *root = createExpressionTree(postfix);
  printf("Result: %d\n", eval(root));

  return 0;
}
