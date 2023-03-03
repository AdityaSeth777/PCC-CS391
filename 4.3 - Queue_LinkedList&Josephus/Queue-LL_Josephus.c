#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void enqueue(struct queue* q, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
        q->rear->next = q->front;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
        q->rear->next = q->front;
    }
}
//Aditya Seth - setha4195@gmail.com
int dequeue(struct queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    int data;
    if (q->front == q->rear) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } else {
        struct node* temp = q->front;
        data = temp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return data;
}

void display(struct queue* q) {
    struct node* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != q->front);
        printf("\n");
    }
}

void josephus(int n, int k) {
    struct queue q;
    q.front = NULL;
    q.rear = NULL;
    for (int i = 1; i <= n; i++) {
        enqueue(&q, i);
    }
    printf("The order of elimination is: ");
    while (q.front != NULL) {
        for (int i = 0; i < k-1; i++) {
            enqueue(&q, dequeue(&q));
        }
        printf("%d ", dequeue(&q));
    }
    printf("\n");
}

int main() {
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the step size: ");
    scanf("%d", &k);
    josephus(n, k);
    return 0;
}
