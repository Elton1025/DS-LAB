#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool areTreesEqual(struct Node* root1, struct Node* root2) {
  if (root1 == NULL && root2 == NULL) {
    return true;
  }

  if (root1 == NULL || root2 == NULL) {
    return false;
  }

  return (root1->data == root2->data &&
          areTreesEqual(root1->left, root2->left) &&
          areTreesEqual(root1->right, root2->right));
}

int main() {
  struct Node *root1 = NULL;
  struct Node *root2 = NULL;

  printf("Create the first binary tree:\n");
  root1 = createBinaryTree();

  printf("Create the second binary tree:\n");
  root2 = createBinaryTree();

  if (areTreesEqual(root1, root2)) {
    printf("Both trees are equal.\n");
  } else {
    printf("Trees are not equal.\n");
  }

  return 0;
}
