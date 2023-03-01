#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void prefix_to_postfix(char* prefix, char* postfix) {
    int len = strlen(prefix);
    strrev(prefix);  // reverse the prefix expression
    for (int i = 0; i < len; i++) {
        if (isdigit(prefix[i])) {
            postfix[strlen(postfix)] = prefix[i];
        }
        else if (is_operator(prefix[i])) {
            char op1 = pop();
            char op2 = pop();
            postfix[strlen(postfix)] = op1;
            postfix[strlen(postfix)] = op2;
            postfix[strlen(postfix)] = prefix[i];
            push(postfix[strlen(postfix)-1]);
        }
    }
    while (top != -1) {
        postfix[strlen(postfix)] = pop();
    }
    strrev(postfix);  // reverse the postfix expression to get the correct order
}

int main() {
    char prefix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);
    prefix_to_postfix(prefix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
