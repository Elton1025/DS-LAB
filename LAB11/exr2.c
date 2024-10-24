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

struct Node* minValueNode(struct Node* node) {
  struct Node* current = node;
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current;
}

struct Node* deleteNode(struct Node* root, int data) {
  if (root == NULL) {
    return root;
  }

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }

    struct Node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
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

  printf("Enter data to delete: ");
  scanf("%d", &data);
  deleteNode(root, data);

  printf("Inorder traversal of the BST after deletion: ");
  printBinaryTree(root);
  printf("\n");

  return 0;
}
