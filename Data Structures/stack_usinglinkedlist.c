// iam to tired to complete today will be working on this tommorrow
//implementing all the functionality of stack using linked list

//too messy code puerly unmaintainable

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


struct Node* pop(struct Node* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow cant pop element\n");
    }

    else{
        struct Node* a= ptr;
        struct Node* b= ptr->next;
        free(a);

        ptr= b;

        // printf("%d has been poped out from the stack\n", *(a->data));
    }
    return ptr;
}


int peek(struct Node* ptr,int position){
    struct Node* a= ptr;
    int i=0;

    while(i<position-1 && a!=NULL){
        a= a->next;
        i++;
    }
    if(a!= NULL){
    return (a->data);
    }

    else{
        return -1;
    }
}




int main(){

    
    struct Node* top;


    top= (struct Node*) malloc(sizeof(struct Node));


    //initializing linked-list
    top= NULL;


    top=push(top,90);
    top=push(top,60);
    top=push(top,80);
    top=push(top,9);



    linkedlist_traversal(top);
    printf("\n");
    // printf("\n");
    // top=push(top,69);
    // top=push(top,1);
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);

    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=pop(top);
    // printf("\n");
    // linkedlist_traversal(top);
    // top=push(top,100);
    // top=push(top,200);
    // top=push(top,300);
    // linkedlist_traversal(top);

    
    printf("The peeked element from the stack is %d",peek(top,3) );
    return 0;
}