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

struct Node* createBinaryTree() {
  int data;
  printf("Enter data (-1 for no node): ");
  scanf("%d", &data);

  if (data == -1) {
    return NULL;
  }

  struct Node* root = newNode(data);
  printf("Enter left child of %d\n", data);
  root->left = createBinaryTree();
  printf("Enter right child of %d\n", data);
  root->right = createBinaryTree();

  return root;
}

void printBinaryTree(struct Node* root) {
  if (root != NULL) {
    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
  }
}

int main() {
  struct Node* root = NULL;

  printf("Create the binary tree:\n");
  root = createBinaryTree();

  printf("Inorder traversal of the tree: ");
  printBinaryTree(root);
  printf("\n");

  return 0;
}
