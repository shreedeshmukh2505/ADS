#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a sample binary tree
struct Node* createSampleTree() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}

// Function to perform non-recursive Preorder Traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
    }
}

// Function to count leaf nodes non-recursively
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    int leafCount = 0;

    while (top >= 0) {
        struct Node* current = stack[top--];

        if (current->left == NULL && current->right == NULL) {
            leafCount++;
        }
        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
    }

    return leafCount;
}

// Function to count total number of nodes non-recursively
int countTotalNodes(struct Node* root) {
    if (root == NULL) return 0;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    int nodeCount = 0;

    while (top >= 0) {
        struct Node* current = stack[top--];
        nodeCount++;

        if (current->right) {
            stack[++top] = current->right;
        }
        if (current->left) {
            stack[++top] = current->left;
        }
    }

    return nodeCount;
}

// Function to calculate height of the tree non-recursively
int treeHeight(struct Node* root) {
    if (root == NULL) return 0;

    struct Node* stack[100];
    int heights[100];
    int top = -1;
    stack[++top] = root;
    heights[top] = 1;
    int maxHeight = 0;

    while (top >= 0) {
        struct Node* current = stack[top];
        int currentHeight = heights[top--];

        if (current->left == NULL && current->right == NULL) {
            if (currentHeight > maxHeight) {
                maxHeight = currentHeight;
            }
        }
        if (current->right) {
            stack[++top] = current->right;
            heights[top] = currentHeight + 1;
        }
        if (current->left) {
            stack[++top] = current->left;
            heights[top] = currentHeight + 1;
        }
    }

    return maxHeight;
}

int main() {
    struct Node* root = createSampleTree();

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    int leafCount = countLeafNodes(root);
    printf("Leaf Nodes Count: %d\n", leafCount);

    int totalNodes = countTotalNodes(root);
    printf("Total Nodes Count: %d\n", totalNodes);

    int height = treeHeight(root);
    printf("Height of Tree: %d\n", height);

    return 0;
}
