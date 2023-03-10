Question -> Create binary search tree and implement Preorder, Inorder
and Postorder traversal non-recursively in C


This code implements a binary search tree data structure in C, which allows the user to insert nodes into the tree and traverse it using different non-recursive methods: preorder, inorder, and postorder.

The program first defines the structure of the binary search tree node using the "struct Node" data type. Each node contains an integer data value, a pointer to the left child node, and a pointer to the right child node.

The "newNode" function is then defined to create a new node with the given data value. It dynamically allocates memory for the new node and initializes its data and child pointers to NULL.

The "insertNode" function is used to insert a new node into the binary search tree. It takes a node pointer and a data value as input parameters and recursively traverses the tree to find the correct location for the new node. If the input node is NULL, the function creates a new node with the given data value. If the data value is less than the node's data value, the function calls itself recursively with the left child node. Otherwise, the function calls itself recursively with the right child node.

The "preorder," "inorder," and "postorder" functions are used to traverse the binary search tree using non-recursive methods. The preorder function prints the node's data value, pushes its right child node onto a stack, and then pushes its left child node onto the stack. It continues popping nodes off the stack and repeating the process until the stack is empty. The inorder function uses two stacks to traverse the tree. It starts at the root node and pushes each left child node onto the first stack until it reaches a node with no left child. It then pops nodes off the first stack, prints their data value, and pushes their right child node onto the second stack. It continues popping nodes off the first stack until it is empty, and then repeats the process with the second stack until it is also empty. The postorder function also uses two stacks to traverse the tree. It pushes the root node onto the first stack and then pops nodes off the stack, pushing their children onto the first stack in reverse order (right child first, then left child). It also pushes each popped node onto the second stack. When the first stack is empty, the function pops nodes off the second stack and prints their data value.

The main function starts by initializing the root node pointer to NULL and asking the user to input data values to insert into the binary search tree. The user can input any number of values, and the program will stop accepting inputs when the user enters -1. Once the binary search tree is constructed, the program asks the user which type of traversal they would like to perform (preorder, inorder, or postorder). The user can input a choice from 1 to 3, and the program will call the corresponding function to traverse the tree using the selected method. If the user enters an invalid choice, the program will display an error message.

Finally, the main function returns 0 to indicate successful completion of the program.