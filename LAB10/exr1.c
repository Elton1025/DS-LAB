#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Stack {
    int size;
    int top;
    struct Node** array;
};

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->size * sizeof(struct Node*));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top - 1 == stack->size;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, struct Node* node) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}

struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

void inOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    struct Node* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void postOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    struct Node* current = root;

    do {
        while (current != NULL) {
            if (current->right != NULL)
                push(stack, current->right);
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        if (current->right != NULL && !isEmpty(stack) && stack->array[stack->top] == current->right) {
            pop(stack);
            push(stack, current);
            current = current->right;
        } else {
            printf("%d ", current->data);
            current = NULL;
        }
    } while (!isEmpty(stack));
}

void preOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack(100);
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* node = pop(stack);
        printf("%d ", node->data);

        if (node->right)
            push(stack, node->right);
        if (node->left)
            push(stack, node->left);
    }
}

struct Node* findParent(struct Node* root, int target) {
    if (root == NULL || root->data == target)
        return NULL;

    if ((root->left && root->left->data == target) || (root->right && root->right->data == target))
        return root;

    struct Node* left = findParent(root->left, target);
    if (left != NULL)
        return left;

    struct Node* right = findParent(root->right, target);
    return right;
}

int depth(struct Node* node) {
    if (node == NULL)
        return 0;
    else {
        int lDepth = depth(node->left);
        int rDepth = depth(node->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int printAncestors(struct Node* root, int target) {
    if (root == NULL)
        return 0;

    if (root->data == target)
        return 1;

    if (printAncestors(root->left, target) || printAncestors(root->right, target)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to construct the binary tree from user input
struct Node* constructTree() {
    int data;
    printf("Enter the data for the node (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct Node* node = newNode(data);
    printf("Enter the left child of %d:\n", data);
    node->left = constructTree();
    printf("Enter the right child of %d:\n", data);
    node->right = constructTree();

    return node;
}

int main() {
    struct Node* root = NULL;
    int target;

    printf("Construct the binary tree:\n");
    root = constructTree();

    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");

    printf("Enter the element to find its parent: ");
    scanf("%d", &target);
    struct Node* parent = findParent(root, target);
    if (parent != NULL) {
        printf("Parent of %d is: %d\n", target, parent->data);
    } else {
        printf("Parent not found or %d is the root.\n", target);
    }

    printf("Depth of the tree is: %d\n", depth(root));

    printf("Enter the element to find its ancestors: ");
    scanf("%d", &target);
    printf("Ancestors of %d are: ", target);
    printAncestors(root, target);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
