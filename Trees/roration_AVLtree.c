#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int getHeight(struct node *root) {
  if (root == NULL) {
    return 0;
  }

  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);

  int height;
  if (left_height > right_height) {
    height = left_height;
  } else {
    height = right_height;
  }
  
  return 1 + height;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int getBalanceFactor(struct node * n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}


struct node* createNode(int data){
    struct node* n;

    n = (struct node*) malloc(sizeof(struct node));

    n->data = data;
    n->left =  NULL;
    n->right=  NULL;

    return n;
}

void preorderTraversal(struct node* root){
    if(root != NULL){
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);;
    }
}


struct node* rightRotate(struct node* y){

  //pointing to some elements in tree
  struct node* x = y->left;
  struct node* v = x->right;

  x->right = y;
  y->left = v;

  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
  return x;

}

struct node* leftRotate(struct node* x){

  //pointing to some elements in tree
  struct node* y = x->right;
  struct node* v = y->left;

 
  y->left = x;
  x->right = v;

  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
  return y;

}

//inserting a node in correct position and also performing rotation accordingly
struct node *insert(struct node* node, int key){
    if (node == NULL)
        return  createNode(key);
 
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
 
    // Left Left Case
        if(bf>1 && key < node->left->data){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->data){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}





int main(){
 
  struct node* root = NULL;

  root = insert(root,1);
  root = insert(root,2);
  root = insert(root,3);
  root = insert(root,4);
  root = insert(root,5);
  root = insert(root,6);

  preorderTraversal(root);

    return 0;
}