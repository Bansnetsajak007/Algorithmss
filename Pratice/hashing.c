#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct Entry {
    int key;
    int value;
    struct Entry* next;
};

// Hash table
struct Entry* hashTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;  // key MOD tableSize
}

// Insert into hash table
void insert(int key, int value) {
    int hashIndex = hashFunction(key);
    struct Entry* newEntry = (struct Entry*)malloc(sizeof(struct Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = NULL;

    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newEntry;
    } else {
        struct Entry* temp = hashTable[hashIndex];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEntry;
    }
}

// Search in hash table
int search(int key) {
    int hashIndex = hashFunction(key);
    struct Entry* temp = hashTable[hashIndex];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1; // Element not found
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert key-value pairs into hash table
    insert(1, 10);
    insert(2, 20);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);

    // Search for values in hash table
    printf("Value for key 1: %d\n", search(1));
    printf("Value for key 42: %d\n", search(42));
    printf("Value for key 12: %d\n", search(12));
    printf("Value for key 15: %d\n", search(15)); // Key not present

    return 0;
}