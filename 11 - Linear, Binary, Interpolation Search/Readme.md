This code implements three different search techniques - Linear Search, Binary Search, and Interpolation Search - in C.

```bash
Linear search:
Linear search is a simple search algorithm that checks each element of the array one by one until it finds the desired element. It starts at the beginning of the array and compares each element with the target element. If the target element is found, the index of that element is returned, otherwise, it returns -1. The time complexity of the linear search algorithm is O(n).

Binary search:
Binary search is a search algorithm that works on sorted arrays. It works by repeatedly dividing the search interval in half until the target element is found or the search interval is empty. It compares the target element with the middle element of the array. If the target element is equal to the middle element, then the search is successful, otherwise, it discards the half of the array in which the target element cannot be present and repeats the process on the remaining half. The time complexity of the binary search algorithm is O(log n).

Interpolation search:
Interpolation search is an improved version of binary search for uniformly distributed arrays. It works by finding the position of the target element in the array by linear interpolation between the first and last index of the array. It assumes that the elements in the array are uniformly distributed and uses the formula to calculate the expected position of the target element. Then it compares the target element with the element at the calculated position. If the target element is found, the index of that element is returned, otherwise, it discards the half of the array in which the target element cannot be present and repeats the process on the remaining half. The time complexity of the interpolation search algorithm is O(log log n) on average, but it can be as bad as O(n) in the worst case.
```

First, the program prompts the user to enter the size of an array and the elements of the array. Then, it displays a menu to the user to choose a search technique. The user enters their choice and the element to search for.

Based on the user's choice, the program calls the corresponding search function - linear_search(), binary_search(), or interpolation_search() - passing the array, its size, and the element to search for as arguments.

The search functions return the position of the element if found in the array or -1 if not found. The main() function assigns the returned value to the variable pos and then checks if pos is -1 or not. If pos is -1, the program prints "Element not found!". Otherwise, it prints "Element found at position %d." with the value of pos.

Finally, the program returns 0 to indicate successful execution.