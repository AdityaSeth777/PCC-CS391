#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % MAX_QUEUE_SIZE == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to add an element to the queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
    }
    queue[rear] = data;
    printf("%d has been enqueued to the queue\n", data);
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    } else if (front == rear) {
        printf("%d has been dequeued from the queue\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("%d has been dequeued from the queue\n", queue[front]);
        front = (front + 1) % MAX_QUEUE_SIZE;
    }
}

// Function to display the queue
void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (i = front; i != rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d\n", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
