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

int height(struct Node* node) {
  if (node == NULL) {
    return 0;
  } else {
    int lheight = height(node->left);
    int rheight = height(node->right);

    if (lheight > rheight) {
      return (lheight + 1);
    } else {
      return (rheight + 1);
    }
  }
}

void printGivenLevel(struct Node* root, int level) {
  if (root == NULL) {
    return;
  }
  if (level == 1) {
    printf("%d ", root->data);
  } else if (level > 1) {
    printGivenLevel(root->left, level - 1);
    printGivenLevel(root->right, level - 1);
  }
}

void printLevelOrder(struct Node* root) {
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++) {
    printGivenLevel(root, i);
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

  printf("Level order traversal of binary tree is \n");
  printLevelOrder(root);

  return 0;
}
