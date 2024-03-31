#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);

int main() {
  Node* head = NULL; // Initialize an empty list

  // Insert elements at the beginning
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 10);
  insertAtBeginning(&head, 15);

  printf("List after insertion at beginning: ");
  printList(head);

  // Insert elements at the end
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 25);

  printf("List after insertion at end: ");
  printList(head);

  // Delete a node
  deleteNode(&head, 15);

  printf("List after deleting 15: ");
  printList(head);

  return 0;
}

// Function to create a new node
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head_ref, int data) {
  Node* newNode = createNode(data);
  newNode->next = *head_ref;
  *head_ref = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int data) {
  Node* newNode = createNode(data);
  if (*head_ref == NULL) {
    *head_ref = newNode;
    return;
  }

  Node* last = *head_ref;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = newNode;
}

// Function to delete a node with a specific value
void deleteNode(Node** head_ref, int key) {
  // Handle empty list
  if (*head_ref == NULL) return;

  // Special case: the head node needs to be deleted
  if ((*head_ref)->data == key) {
    Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    return;
  }

  // Traverse the list to find the node and the node before it
  Node* current = *head_ref;
  Node* prev = NULL;
  while (current != NULL && current->data != key) {
    prev = current;
    current = current->next;
  }

  // If the node wasn't found, return
  if (current == NULL) return;

  // Update the link to bypass the node being deleted
  prev->next = current->next;
  free(current);
}

// Function to print the contents of the list
void printList(Node* head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}
