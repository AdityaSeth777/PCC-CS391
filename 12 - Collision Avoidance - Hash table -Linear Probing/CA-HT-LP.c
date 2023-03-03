#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

int linear_probe(int hash_table[], int key) {
    int index = hash(key);

    while (hash_table[index] != -1 && hash_table[index] != key) {
        index = (index + 1) % SIZE;
    }

    return index;
}

void insert(int hash_table[], int key) {
    int index = hash(key);

    if (hash_table[index] == -1) {
        hash_table[index] = key;
    } else {
        index = linear_probe(hash_table, key);
        hash_table[index] = key;
    }
}

int search(int hash_table[], int key) {
    int index = hash(key);

    while (hash_table[index] != -1) {
        if (hash_table[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
    }

    return -1;
}

void display(int hash_table[]) {
    printf("Hash Table:\n");
    printf("Index\tValue\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t%d\n", i, hash_table[i]);
    }
}

int main() {
    int hash_table[SIZE];

    // Initialize hash table with -1
    for (int i = 0; i < SIZE; i++) {
        hash_table[i] = -1;
    }

    int choice, key, index;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(hash_table, key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                index = search(hash_table, key);
                if (index == -1) {
                    printf("Key not found.\n");
                } else {
                    printf("Key found at index %d.\n", index);
                }
                break;
            case 3:
                display(hash_table);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
//Aditya Seth - setha4195@gmail.com
    return 0;
}
