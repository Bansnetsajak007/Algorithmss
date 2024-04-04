#include <stdio.h>
#include <stdlib.h>

// Define a Node struct
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Append a node to the end of the list
void append(struct Node** head_ref, int data) {
    struct Node* new_node = newNode(data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

// Print the contents of the list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Append some nodes to the list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);

    // Print the contents of the list
    printList(head);

    return 0;
}
