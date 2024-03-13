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


struct Node* Enqueue(struct Node* ptr, int data){
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


struct Node* Dequeue(struct Node* ptr){
    if(isEmpty(ptr)){
        printf("stack underflow cant pop element\n");
    }

    else{
        struct Node* a= ptr;
        struct Node* b= ptr->next;        
        
        while(b->next!= NULL){
            a= a->next;
            b= b->next;
        }
        free(b);
        a->next= NULL;
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


    top=Enqueue(top,90);
    top=Enqueue(top,60);
    top=Enqueue(top,80);
    top=Enqueue(top,9);
    top=Enqueue(top,69);
    top=Enqueue(top,100);

    linkedlist_traversal(top);
    printf("\n");
    // Dequeue(top);
    // Dequeue(top);
    Dequeue(top);
    top=Enqueue(top,24);
    linkedlist_traversal(top);
    // printf("\n");
    // top=Enqueue(top,400);
    // linkedlist_traversal(top);
    
    // printf("\n");
    // Dequeue(top);
    // linkedlist_traversal(top);

    // printf("The peeked value is %d", peek(top, 5));


    return 0;
}