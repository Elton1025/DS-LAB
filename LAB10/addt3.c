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

struct Node* copyTree(struct Node* original) {
  if (original == NULL) {
    return NULL;
  }

  struct Node* copy = newNode(original->data);
  copy->left = copyTree(original->left);
  copy->right = copyTree(original->right);

  return copy;
}

void printBinaryTree(struct Node* root) {
  if (root != NULL) {
    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
  }
}

int main() {
  struct Node *original = NULL;
  struct Node *copy = NULL;

  printf("Create the original binary tree:\n");
  original = createBinaryTree();

  copy = copyTree(original);

  printf("Inorder traversal of the original tree: ");
  printBinaryTree(original);
  printf("\n");

  printf("Inorder traversal of the copied tree: ");
  printBinaryTree(copy);
  printf("\n");

  return 0;
}
