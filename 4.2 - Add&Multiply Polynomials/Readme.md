Question -> Write a C program to add and multiply two
polynomials


The given code implements the addition and multiplication of two polynomials using linked lists. The program takes the degree and coefficients of two polynomials as input from the user and stores them in two separate linked lists. The addition and multiplication of the two polynomials are then performed using the two linked lists.

The linked list is represented by the structure PolyNode, which contains the coefficient and exponent of the polynomial term, and a pointer to the next node. The createNode() function creates a new node with the given coefficient and exponent and returns a pointer to it. The insertPoly() function inserts a new node at the end of the linked list pointed to by the headRef pointer.

The addPoly() function takes two polynomial linked lists as input and returns a new polynomial linked list that represents the sum of the two input polynomials. It iterates over the two input linked lists using two pointers poly1 and poly2 and compares the exponents of the polynomial terms at the current positions. If the exponents are equal, it creates a new node with the sum of the coefficients of the two terms, otherwise it creates a new node with the term that has the higher exponent. It continues this process until it reaches the end of one of the input linked lists. It then appends the remaining nodes of the other linked list to the end of the result linked list.

The multiplyPoly() function takes two polynomial linked lists as input and returns a new polynomial linked list that represents the product of the two input polynomials. It iterates over the first input linked list using a pointer poly1 and for each term, it iterates over the second input linked list using a pointer poly2 and creates a new node with the product of the coefficients and the sum of the exponents of the two terms. It then inserts this new node at the end of the result linked list.

Finally, the displayPoly() function prints out the polynomial represented by the given linked list in a human-readable format.

The main function first takes input from the user for the degree and coefficients of two polynomials using the scanf() function. It then creates two linked lists representing the two polynomials using the insertPoly() function. It displays the two input polynomials using the displayPoly() function, and then performs addition and multiplication of the two polynomials using the addPoly() and multiplyPoly() functions, respectively. The resulting polynomials are displayed using the displayPoly() function again. The program then terminates.