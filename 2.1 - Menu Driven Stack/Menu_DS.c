#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

typedef struct Stack stack;

void initialize(stack *s) {
    s->top = -1;
}

int is_full(stack *s) {
    return s->top == MAX_SIZE - 1;
}

int is_empty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int x) {
    if (is_full(s)) {
        printf("Error: Stack overflow\n");
        return;
    }
    s->top++;
    s->items[s->top] = x;
}

int pop(stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    int temp = s->items[s->top];
    s->top--;
    return temp;
}

int peek(stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        return -1;
    }
    return s->items[s->top];
}

void display(stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

int main() {
    stack s;
    initialize(&s);
    int choice, x;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &x);
                push(&s, x);
                break;
            case 2:
                x = pop(&s);
                if (x != -1) {
                    printf("Popped element: %d\n", x);
                }
                break;
            case 3:
                x = peek(&s);
                if (x != -1) {
                    printf("Top element: %d\n", x);
                }
                break;
            case 4:
                display(&s);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}
