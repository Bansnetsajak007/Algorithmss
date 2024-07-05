    #include <stdio.h>
    #include <stdlib.h>

    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
    };

    struct Node* createNode(int data) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    struct Node* insert(struct Node* root, int data) {
        if(root == NULL) return createNode(data);

        if(data < root ->data) {
            root ->left = insert(root->left , data); 
        } else if(data > root -> data) {
            root ->right = insert(root->right, data);
        }

        return root;
    }

    void inOrderTraveral(struct Node* root) {
        if(root != NULL) {
            inOrderTraveral(root->left);
            printf("%d\t", root->data);
            inOrderTraveral(root->right);
        }
    }



// Function to find the minimum value node in a tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    
    // Loop to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Function to delete a node in a BST
struct Node* deleteNode(struct Node* root, int data) {
    // Base case
    if (root == NULL) return root;
    
    // Recur down the tree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: Get the in-order successor
        struct Node* temp = minValueNode(root -> right);
        
        // Copy the in-order successor's content to this node
        root->data = temp->data;
        
        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 8);
    insert(root, 2);
    insert(root, 1);
    insert(root, 4);
    insert(root, 10);
    insert(root, 9);
    insert(root, 12);

    // root = insert(root, 3);
    // insert(root, 2);
    // insert(root, 4);
    // insert(root, 5);
    
    // printf("In-order traversal before deletion: ");
    // inOrderTraveral(root);
    // printf("\n");
    
    root = deleteNode(root, 10);
    printf("In-order traversal after deleting 10: ");
    inOrderTraveral(root);
    printf("\n");
     
    
    return 0;
}
