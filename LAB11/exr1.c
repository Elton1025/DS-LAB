#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

struct Node* insert(struct Node* node, int data) {
  if (node == NULL) {
    return newNode(data);
  }

  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  }

  return node;
}

void printBinaryTree(struct Node* root) {
  if (root != NULL) {
    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
  }
}

int main() {
  struct Node *root = NULL;
  int data;

  printf("Enter data for the root node: ");
  scanf("%d", &data);
  root = insert(root, data);

  while (1) {
    printf("Enter data to insert (-1 to stop): ");
    scanf("%d", &data);
    if (data == -1) break;
    insert(root, data);
  }

  printf("Inorder traversal of the BST: ");
  printBinaryTree(root);
  printf("\n");

  return 0;
}
