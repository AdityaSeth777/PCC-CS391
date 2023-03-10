Question -> Write a program to sort an array using Merge sort in C


This program implements Merge sort algorithm to sort an array of integers in C language.

Merge sort is a divide-and-conquer algorithm that recursively divides the array into two halves until each subarray contains only one element. Then, it merges the subarrays in a sorted order.

The merge() function is used to merge two sorted subarrays into a single sorted array. It takes four arguments: the array to be sorted, the starting index of the first subarray, the ending index of the first subarray (i.e., the last index of the first subarray is m), and the ending index of the second subarray (i.e., the last index of the second subarray is r). The function first creates two temporary arrays L[] and R[] to store the elements of the subarrays. Then, it compares the first elements of the two subarrays and adds the smaller element to the final array. This process is repeated until all the elements of both subarrays are added to the final array.

The merge_sort() function is used to divide the array into two halves and call the merge() function on each half until the subarrays contain only one element. It takes three arguments: the array to be sorted, the starting index of the subarray to be sorted (i.e., the left-most index of the array), and the ending index of the subarray to be sorted (i.e., the right-most index of the array). The function first checks if the subarray has more than one element. If it does, it calculates the middle index and calls merge_sort() on the first half and the second half. Finally, it calls merge() on the two halves to merge them in a sorted order.

In the main() function, the program prompts the user to enter the size of the array and the elements of the array. Then, it calls the merge_sort() function to sort the array in a non-decreasing order. Finally, it prints the sorted array.