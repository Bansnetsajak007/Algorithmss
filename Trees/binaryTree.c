#include <stdio.h>
#include <stdlib.h>

// Structure representing a node in the binary tree
typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* newNode(int data) {
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    return newNode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  } else {
    printf("Duplicate value (%d) ignored\n", data);
  }

  return root;
}

void inOrderTraversal(Node* root) {
  if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
  }
}

int main() {
  Node* root = NULL;

  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  root = insert(root, 7);

  printf("In-order traversal: ");
  inOrderTraversal(root);
  printf("\n");

  return 0;
}
