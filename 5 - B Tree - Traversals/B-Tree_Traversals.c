#include <stdio.h>
#include <stdlib.h>

// Definition of the binary search tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Insert a node in the binary search tree
struct Node* insertNode(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

// Non-recursive Preorder traversal of the binary search tree
void preorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;
    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

// Non-recursive Inorder traversal of the binary search tree
void inorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* node = root;

    while (top >= 0 || node != NULL) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        printf("%d ", node->data);
        node = node->right;
    }
}

// Non-recursive Postorder traversal of the binary search tree
void postorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;
    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }
    while (top2 >= 0) {
        struct Node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

int main() {
    struct Node* root = NULL;
    int data, choice;
    do {
        printf("Enter a data to insert into the binary search tree (or -1 to stop):\n");
        scanf("%d", &data);
        if (data != -1) {
            root = insertNode(root, data);
        }
    } while (data != -1);

printf("Enter the type of traversal (1 = Preorder, 2 = Inorder, 3 = Postorder):\n");
scanf("%d", &choice);

switch (choice) {
    case 1:
        printf("Preorder traversal: ");
        preorder(root);
        break;
    case 2:
        printf("Inorder traversal: ");
        inorder(root);
        break;
    case 3:
        printf("Postorder traversal: ");
        postorder(root);
        break;
    default:
        printf("Invalid choice.\n");
        break;
}

return 0;
}
