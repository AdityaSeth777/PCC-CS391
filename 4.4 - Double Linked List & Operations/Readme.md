Question -> Implement Doubly Linked List and perform insertion,
deletion, display and reverse in C


```This code is an implementation of a doubly linked list in C. It defines a Node struct with three members: data, prev (a pointer to the previous node in the list), and next (a pointer to the next node in the list).```

The program then defines several functions for working with doubly linked lists:

insertAtBeginning: Inserts a new node at the beginning of the list.
insertAtEnd: Inserts a new node at the end of the list.
deleteNode: Deletes a given node from the list.
display: Displays the list in both forward and reverse order.
reverse: Reverses the order of the list.
The main function of the program presents a menu to the user, allowing them to perform operations on the doubly linked list. The user can choose to insert a node at the beginning or end of the list, delete a node, display the list, reverse the list, or exit the program.

The switch statement in the main function determines which operation to perform based on the user's input. The appropriate function is called for each operation, and the program continues to loop until the user chooses to exit.

Overall, this program provides a basic implementation of a doubly linked list in C, allowing the user to perform several common operations on the list through a menu-driven interface.