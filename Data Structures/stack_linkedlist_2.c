//implementing stack_top and stack_bottom funcations 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlist_traversal(struct Node* ptr){

    while(ptr != NULL){
        printf("ELement: %d\n",ptr->data);
        ptr= ptr->next;
    }
}


int isEmpty(struct Node* ptr){
    if(ptr== NULL){
        return 1;
    }

    else{
        return 0;
    }
}

int isFull(struct Node* ptr){
    struct Node* n= (struct Node*)  malloc(sizeof(struct Node));

    if (n == NULL){
        return 1;
    }

    else {
        return 0;
    }
}


struct Node* push(struct Node* ptr, int data){
    if(isFull(ptr)){
        printf("stack overflow");
    }

    else{

    struct Node* n= (struct Node*)  malloc(sizeof(struct Node));
    n->data= data;
    n->next= ptr;
    ptr = n;

    return ptr;
    
    }

}

int stack_top(struct Node* ptr){

    printf("The topmost element is %d\n", (ptr->data));

}

int stack_bottom(struct Node* ptr){

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    printf("The bottom most element is %d", (ptr->data));    

}


int main(){

    
    struct Node* top;

    top= (struct Node*) malloc(sizeof(struct Node));

    top= NULL;

    top=push(top,0);
    top=push(top,90);
    top=push(top,60);
    top=push(top,80);
    top=push(top,9);
    top=push(top,1);



    linkedlist_traversal(top);
    printf("\n");

    stack_top(top);
    stack_bottom(top);
    return 0;
}