    // case 4: inserting element after given node of linked list. time complexity is O(1).


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

struct Node *insert_after_node(struct Node* head,int data,struct Node* pointer){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));

    ptr->data = data;

    // pointer->next = ptr;

    ptr->next = pointer->next;

    pointer->next = ptr;

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
    head= insert_after_node(head,69,third);
    linkedlist_traversal(head);

    return 0;
}

