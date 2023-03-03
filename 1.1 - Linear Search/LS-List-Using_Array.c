#include <stdio.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;  // key not found
}
//Aditya Seth - setha4195@gmail.com
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
