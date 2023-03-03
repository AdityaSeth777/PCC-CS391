#include <stdio.h>
#include <stdlib.h>

// Linear search function
int linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary search function
int binary_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x) {
            return m;
        }

        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

// Interpolation search function
int interpolation_search(int arr[], int n, int x) {
    int lo = 0, hi = n - 1;

    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x) {
            return pos;
        }

        if (arr[pos] < x) {
            lo = pos + 1;
        } else {
            hi = pos - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n], i;
    printf("Enter the elements of array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice, x, pos;
    printf("Choose a search technique:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Interpolation Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the element to search: ");
    scanf("%d", &x);

    switch (choice) {
        case 1:
            pos = linear_search(arr, n, x);
            break;
        case 2:
            pos = binary_search(arr, 0, n - 1, x);
            break;
        case 3:
            pos = interpolation_search(arr, n, x);
            break;
        default:
            printf("Invalid choice!\n");
            return -1;
    }

    if (pos == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at position %d.\n", pos);
    }

    return 0;
}
