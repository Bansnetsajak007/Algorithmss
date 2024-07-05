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

    int main() {
        struct Node* root = NULL;
        root = insert(root, 4);
        insert(root, 1);
        insert(root, 3);
        insert(root, 2);

        
        printf("In-order traversal of the BST: ");
        inOrderTraveral(root);
        
        return 0;
    }
