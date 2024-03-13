    // case 1: deletion of element at beginning of linked list. time complexity is O(1)


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


struct Node* deletion_in_between(struct Node* head,int index){
    struct Node* a= head;

    struct Node* b= head->next;

    for(int i=0;i<index-1;i++){
       a= a->next;
       b= b->next;
    }

    a->next = b->next;
    free(b);

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
    head= deletion_in_between(head,1);
    printf("\n");
    linkedlist_traversal(head);

    return 0;
}

