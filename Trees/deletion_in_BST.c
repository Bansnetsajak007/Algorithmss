
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};


void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}


struct node* createNode(int data){
    struct node* n;

    n = (struct node*) malloc(sizeof(struct node));

    n->data = data;
    n->left =  NULL;
    n->right=  NULL;

    return n;
}

 void insert(struct node* root, int key){
    struct node* previous = NULL;  //this previous pointer is important for arranging elements accordingly
    while(root != NULL){
        previous = root;

        if(key == root->data){
            printf("cannot insert %d already exist in tree", key);
            return;
        }
         else if(key < (root->data)){
            root = root->left;
         }

         else{
            root = root->right;
         }
    }
         struct node* new = createNode(key);
         if(key > previous->data){
            previous->right = new;
         }

         else{
            previous->left = new;
         }
    
 }

struct node *inorderpre(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}


 struct node* deletion(struct node* root, int value){
    struct node* ipre;
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value > root->data){
        root->right = deletion(root->right, value);
    }

    else if(value < root->data){
        root->left = deletion(root->left, value);
    }

    //logic to delete the root element of tree
    else{
        ipre = inorderpre(root);
        root->data = ipre->data;
        root->left = deletion(root->left, ipre->data);
    }
 }



int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    // 1    3  5   6
    deletion(p,4);
    printf("\n");
    inOrder(p);
    
    return 0;
}