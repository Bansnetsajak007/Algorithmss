    // case 1: inserting element at beginning of linked list. time complexity is O(1)


#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;  // store number of integer type
    struct Node *next; // Self referencing structure  (simply pointing to same structure)
};


void linkedlist_traversal(struct Node* ptr){

    while(ptr != NULL){
        printf("ELement: %d\n",ptr->data);
        ptr= ptr->next;
    }
}


struct Node* insert_at_beginning(struct Node* head, int data){
    struct Node* ptr = (struct Node *) malloc((sizeof(struct Node)));
    // struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));

    ptr ->next =head;

    ptr ->data =data;

    return ptr;
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
    head->data=8;
    head->next= second;
    
    second->data=11;
    second->next= third;

    third->data=20;
    third->next= fourth;

    fourth->data=52;
    fourth->next=NULL;


    linkedlist_traversal(head);
    printf("\n");
    head= insert_at_beginning(head,90);
    printf("\n");
    linkedlist_traversal(head);

    return 0;
}
