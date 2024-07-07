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
void insertAnyWhere(Node** head_ref, int data , int key);
void printList(Node* head); 
 
int main() { 
  Node* head = NULL; // Initialize an empty list 
 
  // Insert elements at the beginning 
  insertAtBeginning(&head, 8); 
  insertAtEnd(&head, 7); 
  insertAtEnd(&head, 2);     
  insertAtEnd(&head, 3);     
    
  printf("List before insertion: \n");
  printList(head);

  insertAnyWhere(&head, 6, 8);   

  printf("List After insertion: \n");
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

void insertAnyWhere(Node** head_ref, int data , int key) {
    Node* newNode = createNode(data);
    Node* temp = *head_ref;
    while ( temp-> next != NULL) {
        //scan and check wheather key exist in list or not
        if(temp->data == key) {
            newNode -> next = temp->next;
            temp->next = newNode;
            return;
        } else {
            temp = temp->next;
        }
    }
        
    printf("%d not found in list", key);
    return;
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