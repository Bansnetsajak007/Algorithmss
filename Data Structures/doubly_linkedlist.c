#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;  // store number of integer type
    struct Node *next; // Self referencing structure  (simply pointing to same structure)
};


void linkedlist_traversal(struct Node* ptr){

    while(ptr != NULL){
        printf("ELement: %d\n",ptr->data);
        ptr= ptr->next;
    }
}

void traverssal_linkedlist(struct Node* ptr){
    while(ptr != NULL){
        printf("ELement: %d\n",ptr->data);
        ptr= ptr->prev;       
    }
}


struct Node* insert_at_index(struct Node* head,int data,int index){
    int i=0;
    struct Node* ptr = (struct Node *) malloc((sizeof(struct Node)));
    ptr->data =data;

    struct Node* a= head;
    struct Node* b= head->next;

    while(i != index-1){
        a= a->next;
        b= b->next;
        i++;
    }    

    a->next = ptr;
    ptr->prev=a;

    b->prev= ptr;
    ptr->next=b;

    return head;

}



int main(){

    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    

    //allocating dynamic memory from the heap for linkedlist

    head= (struct Node*) malloc(sizeof(struct Node));
    second= (struct Node*) malloc(sizeof(struct Node));
    third= (struct Node*) malloc(sizeof(struct Node));
    fourth= (struct Node*) malloc(sizeof(struct Node));


    //initializing linked-list
    head->prev= NULL;
    head->data=8;
    head->next= second;
    
    second->prev= head;
    second->data=11;
    second->next= third;

    third->prev= second;
    third->data=20;
    third->next= fourth;

    fourth->prev= third;
    fourth->data=52;
    fourth->next=NULL;


    // linkedlist_traversal(head);
    // printf("\n");
    // traverssal_linkedlist(fourth);


    head= insert_at_index(head,69,2);
    linkedlist_traversal(head);

    return 0;
}

