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

bool search(struct Node* root, int data) {
  if (root == NULL) {
    return false;
  }

  if (root->data == data) {
    return true;
  }

  if (data < root->data) {
    return search(root->left, data);
  }

  return search(root->right, data);
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

  printf("Enter data to search for: ");
  scanf("%d", &data);

  if (search(root, data)) {
    printf("Data found in the BST.\n");
  } else {
    printf("Data not found in the BST.\n");
  }

  return 0;
}
