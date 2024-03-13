// A circular linked list is a type of linked list in which the first and the
//  last nodes are also connected to each other to form a circle.
//  Here, the address of the last node consists of the address of the first node.

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;  // store number of integer type
    struct Node *next; // Self referencing structure  (simply pointing to same structure)
};


void linkedlist_traversal(struct Node* head){
    struct Node* p= head;
    while(p->next != head){
        printf("ELement: %d\n",p->data);
        p= p->next;
    }
        printf("ELement: %d\n",p->data);
}


struct Node* insert_at_index(struct Node* head,int data,int index){
    int i=0;
    struct Node* ptr = (struct Node *) malloc((sizeof(struct Node)));
    ptr->data =data;

//     struct Node* p = head->next;

//     while(p->next != head){
//         p=p->next;
//     }
//     p->next=ptr;
//     ptr->next=head;
//     head=ptr;
//     return head;

    struct Node* a = head;
    struct Node* b = head->next;

    while(i!=index-1){
        a=a->next;
        b=b->next;
        i++;
    }

    a->next=ptr;
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
    head->data=8;
    head->next= second;
    
    second->data=11;
    second->next= third;

    third->data=20;
    third->next= fourth;

    fourth->data=52;
    fourth->next=head;


    linkedlist_traversal(head);

    head=insert_at_index(head,69,3);
    head=insert_at_index(head,4,1);

    printf("\n");
    linkedlist_traversal(head);

    return 0;
}

