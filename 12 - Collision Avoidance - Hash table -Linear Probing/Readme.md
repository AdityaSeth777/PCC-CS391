Question -> Write a C program for Collision avoidance in Hash table
using Linear Probing.



```This program demonstrates how to implement collision avoidance in a hash table using linear probing.```

The program defines three main functions:

hash(int key): This function takes a key value as input and returns the hash value by using the modulo operator to ensure that the key is within the range of the hash table.

linear_probe(int hash_table[], int key): This function takes the hash table and the key as inputs and performs linear probing to find the next available index for the key. It starts by computing the initial index using the hash function. If the index is already occupied, the function looks for the next available index by adding 1 to the index and taking the modulus of the hash table size. This process continues until an empty index is found or the key is already in the hash table.

insert(int hash_table[], int key): This function takes the hash table and the key as inputs and inserts the key into the hash table. It uses the hash function to compute the initial index for the key. If the index is empty, the key is inserted at that index. If the index is occupied, the function uses the linear_probe function to find the next available index for the key and inserts the key at that index.

The program also defines a search function that takes the hash table and the key as inputs and searches for the key in the hash table using linear probing. It starts by computing the initial index using the hash function. If the index is occupied and does not contain the key, the function looks for the next index using linear probing until the key is found or an empty index is encountered.

The display function is also defined to display the contents of the hash table.

The main function is responsible for taking user inputs and calling the appropriate functions based on the user's choice. It displays a menu of available operations and prompts the user to choose one. The program exits when the user chooses the "Exit" option.