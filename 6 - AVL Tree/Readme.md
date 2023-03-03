Question -> Write a program to implement AVL tree with suitable
operations in C


```This code implements an AVL (Adelson-Velsky and Landis) tree, which is a self-balancing binary search tree. The AVL tree is balanced based on the heights of the subtrees of each node. The balancing ensures that the height difference between the left and right subtrees is at most 1. This helps to ensure that the time complexity of searching, inserting, and deleting nodes is O(log n) in the worst case.```

The program first defines the structure of an AVL tree node, which includes the data, height, left child, and right child. It also defines several helper functions such as height(), max(), newNode(), rotateLeft(), rotateRight(), balanceFactor(), and insertNode().

The height() function returns the height of the given node. The max() function returns the maximum of two integers. The newNode() function creates a new AVL tree node with the given data. The rotateLeft() and rotateRight() functions perform left and right rotations of the subtree rooted at the given node. The balanceFactor() function returns the balance factor of the given node, which is the difference between the height of the left subtree and the height of the right subtree. The insertNode() function inserts a new node with the given data into the AVL tree and maintains the balance of the tree using the four cases for left-left, left-right, right-right, and right-left.

The main() function takes user input for inserting nodes into the AVL tree using the insertNode() function. It prints the inorder traversal of the AVL tree using the inorder() function. It then takes user input for deleting nodes from the AVL tree using the delete() function (which is not defined in the code provided). It prints the inorder traversal of the AVL tree after each deletion. The program exits when the user enters -1 to stop inserting or deleting nodes.