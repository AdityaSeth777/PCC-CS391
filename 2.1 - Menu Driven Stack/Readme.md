This program implements a menu-driven stack application using an array-based implementation of a stack. The stack is defined using a structure stack which contains an array items and an integer top representing the index of the topmost element in the stack. The stack operations push, pop, peek, and display are implemented as functions that take a pointer to a stack as a parameter.

The initialize function is used to initialize the stack by setting the top value to -1, indicating an empty stack.

The is_full function checks if the stack is full by checking if the top value is equal to MAX_SIZE - 1.

The is_empty function checks if the stack is empty by checking if the top value is equal to -1.

The push function adds an element to the top of the stack. If the stack is full, an error message is printed and the function returns without adding the element. Otherwise, the top value is incremented and the new element is added to the items array at the new top index.

The pop function removes and returns the element at the top of the stack. If the stack is empty, an error message is printed and the function returns -1. Otherwise, the element at the top index is saved to a temporary variable, the top value is decremented, and the saved element is returned.

The peek function returns the element at the top of the stack without removing it. If the stack is empty, an error message is printed and the function returns -1. Otherwise, the element at the top index is returned.

The display function prints the elements of the stack in order from top to bottom. If the stack is empty, a message indicating that the stack is empty is printed.

In the main function, a stack object is created and initialized using the initialize function. The program then enters an infinite loop that displays a menu of options for the user to choose from. The user's choice is read using the scanf function and the appropriate stack operation is performed using a switch statement. The program loops back to the menu after each operation is performed. The program exits when the user chooses the Exit option.