#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Deque;

void initDeque(Deque *dq) {
    dq->arr = (int *) malloc(MAX_SIZE * sizeof(int));
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
}
//Aditya Seth - setha4195@gmail.com
int isFull(Deque *dq) {
    return dq->size == MAX_SIZE;
}

int isEmpty(Deque *dq) {
    return dq->size == 0;
}

void insertFront(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX_SIZE - 1;
    } else {
        dq->front--;
    }

    dq->arr[dq->front] = val;
    dq->size++;
}

void insertRear(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }

    dq->arr[dq->rear] = val;
    dq->size++;
}

int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }

    int val = dq->arr[dq->front];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX_SIZE - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }

    dq->size--;
    return val;
}

int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }

    int val = dq->arr[dq->rear];
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX_SIZE - 1;
    } else {
        dq->rear--;
    }

    dq->size--;
    return val;
}

void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i;
    printf("Deque: ");
    for (i = dq->front; i != dq->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", dq->arr[i]);
    }
    printf("%d\n", dq->arr[i]);
}

int main() {
    Deque dq;
    initDeque(&dq);
    int choice, val;

    while (1) {
        printf("\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertFront(&dq, val);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertRear(&dq, val);
                break;
            case 3:
                val = deleteFront(&dq);
                if (val != -1) {
                    printf("Deleted element: %d\n", val);
                }
                break;
            case 4:
                val = deleteRear(&dq);
                if (val != -1) {
                    printf("Deleted element: %d\n", val);
                }
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
