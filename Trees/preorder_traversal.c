//linked representation of binary tree

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};


void preorderTraversal(struct node* root){
    if(root != NULL){
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);;
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}

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

int main(){
    struct node* p = createNode(9);
    struct node* p1 = createNode(2);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(8);
    struct node* p4 = createNode(17);
    struct node* p5 = createNode(1);
    struct node* p6 = createNode(80);


//linking pointers with specific nodes to maintain acceracy
    p->left = p1; 
    p->right = p2; 
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;


    preorderTraversal(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);

    
    return 0;
}