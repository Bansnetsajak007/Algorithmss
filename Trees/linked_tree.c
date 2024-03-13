//linked representation of binary tree

#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* createNode(int data){
    //structure pointer variable
    struct node* n;

    // allocating size of that variable dynamically
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

    p->left = p1; 
    p->right = p2; 
    
    return 0;
}