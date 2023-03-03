#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Definition of the Priority Queue node
struct Node {
    int data;
    int priority;
};

// Create a new node with the given data and priority
struct Node* newNode(int data, int priority) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->priority = priority;
    return(node);
}

// Check if the given priority queue is empty
int isEmpty(struct Node* queue[], int front, int rear) {
    if (front > rear) {
        return 1;
    }
    return 0;
}

// Check if the given priority queue is full
int isFull(int rear) {
    if (rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}
//Aditya Seth - setha4195@gmail.com
// Enqueue a new node with the given data and priority
void enqueue(struct Node* queue[], int *front, int *rear, int data, int priority) {
    struct Node* node = newNode(data, priority);
    if (isFull(*rear)) {
        printf("Queue is full. Cannot enqueue any more elements.\n");
        return;
    }
    if (*front == -1 && *rear == -1) {
        *front = *rear = 0;
        queue[*rear] = node;
    } else {
        int i;
        for (i = *rear; i >= *front; i--) {
            if (node->priority > queue[i]->priority) {
                queue[i+1] = queue[i];
            } else {
                break;
            }
        }
        queue[i+1] = node;
        (*rear)++;
    }
    printf("%d with priority %d has been enqueued.\n", data, priority);
}

// Dequeue the node with the highest priority from the given priority queue
void dequeue(struct Node* queue[], int *front, int *rear) {
    if (isEmpty(queue, *front, *rear)) {
        printf("Queue is empty. Cannot dequeue any element.\n");
        return;
    }
    struct Node* node = queue[*front];
    printf("%d with priority %d has been dequeued.\n", node->data, node->priority);
    if (*front == *rear) {
        *front = *rear = -1;
    } else {
        (*front)++;
    }
}

int main() {
    int front = -1, rear = -1;
    struct Node* queue[MAX_SIZE];

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data, priority;
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                enqueue(queue, &front, &rear, data, priority);
                break;
            }
            case 2: {
                dequeue(queue, &front, &rear);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}
