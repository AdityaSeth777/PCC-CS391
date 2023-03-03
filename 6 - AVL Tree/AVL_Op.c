#include <stdio.h>
#include <stdlib.h>

// Definition of the AVL tree node
struct Node {
    int data;
    int height;
    struct Node *left;
    struct Node *right;
};

// Get the height of the given node
int height(struct Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

// Get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
//Aditya Seth - setha4195@gmail.com
// Rotate the given subtree to the left
struct Node* rotateLeft(struct Node *node) {
    struct Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

// Rotate the given subtree to the right
struct Node* rotateRight(struct Node *node) {
    struct Node *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}

// Get the balance factor of the given node
int balanceFactor(struct Node *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Insert a node in the AVL tree
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int bf = balanceFactor(node);

    // Left-Left case
    if (bf > 1 && data < node->left->data)
        return rotateRight(node);

    // Right-Right case
    if (bf < -1 && data > node->right->data)
        return rotateLeft(node);

    // Left-Right case
    if (bf > 1 && data > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right-Left case
    if (bf < -1 && data < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Inorder traversal of the AVL tree
void inorder(struct Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int data, choice;

    do {
        printf("Enter a data to insert into the AVL tree (or -1 to stop):\n");
        scanf("%d", &data);
        if (data != -1) {
            root = insert(root, data);
        }
    } while (data != -1);

    printf("AVL tree in inorder traversal:\n");
    inorder(root);

    printf("\nEnter a data to delete from the AVL tree (or -1 to stop):\n");
    scanf("%d", &data);
    while (data != -1) {
        root = delete(root, data);
        printf("AVL tree in inorder traversal:\n");
        inorder(root);
        printf("\nEnter a data to delete from the AVL tree (or -1 to stop):\n");
        scanf("%d", &data);
    }

    return 0;
}
