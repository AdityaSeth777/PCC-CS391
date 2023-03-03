Question -> Implement queue using Circular linked list and
demonstrate JOSEPHUS problem in C


This code implements a circular linked list-based queue data structure to solve the Josephus problem.

The struct node represents a single node in the circular linked list, and has two members - data which holds the value of the node, and next which points to the next node in the list.

The struct queue represents the queue data structure, and has two members - front which points to the front of the queue, and rear which points to the rear of the queue.

The enqueue() function inserts a new node with the given data at the rear of the queue. If the queue is empty, the front and rear pointers are set to the new node, and the rear node's next pointer is set to the front node. Otherwise, the rear node's next pointer is set to the new node, the rear pointer is updated to the new node, and the rear node's next pointer is set to the front node.

The dequeue() function removes the front node from the queue and returns its data. If the queue is empty, it returns -1. If the front and rear nodes are the same, the front and rear pointers are set to NULL after freeing the front node. Otherwise, the front pointer is updated to the next node, the rear node's next pointer is updated to the front node, and the front node is freed.

The display() function prints the elements of the queue in order.

The josephus() function solves the Josephus problem by first initializing a queue with values from 1 to n. It then repeatedly removes the kth person from the queue and prints their value, until the queue becomes empty.

The main() function prompts the user to input the number of people and the step size, and then calls the josephus() function with these values.