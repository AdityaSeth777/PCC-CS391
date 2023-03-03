#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definition of the expression tree node
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Create a new node with the given data
struct Node* newNode(char data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Check if the given character is an operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

// Build an expression tree from the given postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;
    int i;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            struct Node* node = newNode(postfix[i]);
            stack[++top] = node;
        }
        else if (isOperator(postfix[i])) {
            struct Node* node = newNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];
            stack[++top] = node;
        }
    }

    return stack[top];
}

// Evaluate an expression tree
int evaluateExpressionTree(struct Node* root) {
    if (root == NULL) return 0;

    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    int left = evaluateExpressionTree(root->left);
    int right = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }

    return 0;
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    struct Node* root = buildExpressionTree(postfix);
    printf("Expression tree is built.\n");

    int result = evaluateExpressionTree(root);
    printf("Result of evaluation: %d\n", result);

    return 0;
}
