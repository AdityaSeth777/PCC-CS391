#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct stack {
    int top;
    char arr[STACK_SIZE];
} Stack;

void push(Stack* s, char value) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->arr[++s->top] = value;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->arr[s->top--];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(s, infix[i]);
        } else if (infix[i] == ')') {
            while (s->top != -1 && s->arr[s->top] != '(') {
                postfix[j++] = pop(s);
            }
            if (s->top == -1) {
                printf("Invalid expression!\n");
                exit(1);
            }
            pop(s);
        } else {
            while (s->top != -1 && precedence(infix[i]) <= precedence(s->arr[s->top])) {
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }
    }

    while (s->top != -1) {
        if (s->arr[s->top] == '(' || s->arr[s->top] == ')') {
            printf("Invalid expression!\n");
            exit(1);
        }
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    free(s);
}

int main() {
    char infix[STACK_SIZE], postfix[STACK_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, STACK_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
