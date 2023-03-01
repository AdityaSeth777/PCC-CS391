#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

typedef struct stack {
    int top;
    int arr[STACK_SIZE];
} Stack;

void push(Stack* s, int value) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->arr[++s->top] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->arr[s->top--];
}

int evaluate(char* expression) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = -1;

    int i, num1, num2, result;
    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            push(s, expression[i] - '0');
        } else {
            num2 = pop(s);
            num1 = pop(s);
            switch(expression[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(1);
            }
            push(s, result);
        }
    }

    result = pop(s);
    free(s);

    return result;
}

int main() {
    char expression[STACK_SIZE];

    printf("Enter postfix expression: ");
    fgets(expression, STACK_SIZE, stdin);
    expression[strlen(expression) - 1] = '\0';

    printf("Result: %d\n", evaluate(expression));

    return 0;
}
