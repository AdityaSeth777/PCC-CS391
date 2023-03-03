Question -> Implement Linear search on a List using Array in C




```bash
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;  // key not found
}
```

This function linear_search() is defined to search for the element key in the array arr of size n. It traverses the array from the beginning to the end and checks whether the current element is equal to the key. If it finds the key, it returns the index at which it was found, otherwise, it returns -1 to indicate that the element was not found.

```bash
int main() {
    int n, key, index;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    index = linear_search(arr, n, key);
    if (index == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n", index);
    }

    return 0;
}
```

In the main() function, the user is asked to enter the size of the array and the elements of the array. Then, the user is asked to enter the key to search for in the array. The linear_search() function is called with the array, its size, and the key to find the index of the key in the array. The returned index is then checked to determine if the element was found or not. If it was not found, the program prints a message indicating that the element was not found. Otherwise, it prints the index at which the element was found in the array.

Note that the array arr is declared with a variable size using the n variable, which is obtained from the user at runtime. This is called a Variable Length Array (VLA), which is supported by some C compilers. It's important to note that using VLAs may lead to stack overflow issues for large arrays or when memory is limited.
