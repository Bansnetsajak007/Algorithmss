
#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};



struct node* RecursiveSearch(struct node* root, int key){
    if (root == NULL){
        return NULL;
    }

        if(root->data == key){
            return root;    //just root is basicaly a pointer pointing to data of node 
        }

        if((root->data) < key){
            return RecursiveSearch(root->right, key);
        }

        else{
            return RecursiveSearch(root->left, key);
        }

}


struct node* IterativeSearch(struct node* root, int key){

    while(root != NULL){

        if(root->data == key){
            return root;    //just root is basicaly a pointer pointing to data of node 
        }

        if((root->data) < key){
            root = root->right;
        }

        else{
            root = root->left;
        }
}
    return NULL;
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


    struct node* a = RecursiveSearch(p,5);

    if(a != NULL){
        printf("Element found %d\n", a->data);
    }

    else{
        printf("Element not found \n");
    }

    struct node* b = IterativeSearch(p,40);

    if(b != NULL){
        printf("Element found %d\n", b->data);
    }

    else{
        printf("Element not found \n");
    }

    
    return 0;
}