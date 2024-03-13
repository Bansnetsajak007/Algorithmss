#include<stdio.h>
#include<stdlib.h>

struct DEQueue  //(DEQueue means Double ended Queue, In this type of Queue is insertion and deleition operation perform at the both end ie. front and rear)
{
    int size;
    int front;
    int rear;
    int *arr;

};

// ADT for DEQUeue:
//EnQueueR
//EnQueueF
//DeQueueR
//DeQueueF
//IsFull
//IsEmpty

// for checking the Queue is full or not 
int IsFull(struct DEQueue * q)
{
    if(q->rear==q->size-1)
    {
        return 1;
    }
    return 0;
}
// for checking the Queue is Empty or not
int IsEmpty(struct DEQueue *q)
{
    if(q->rear==q->front)
    {
        return 1;
    }
    return 0;
}

// Insertion at the rear end in the DEQueue(NORMAL ENQUEUE OPERATION)
void EnQueueR(struct DEQueue *q,int val)
{
    if(IsFull(q))
    {
        printf("Queue has no space for insertion of the element at rear side\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=val;
        printf("Successfully inserted the elemet at the rear\n");
    }
}

// insertion at the front end in the DEQueue
void EnQueueF(struct DEQueue *q,int val)
{
    if(IsFull(q) || q->front==-1)
    {
        printf("Queue has no space for insertion of the elment at the front side\n");
    }
    else
    {
        q->arr[q->front]=val;
        q->front--;
        printf("Successfullly inserted the element at the front\n");

    }
}

//Deletion at the rear end int the Queue
int DeQueueR(struct DEQueue *q)
{
    if(IsEmpty(q))
    {
        printf("There is no element in the Queue\n");
        return -1;
    }
    else
    {
        int val=q->arr[q->rear];
        q->rear--;
        return val;
    }
}

// Deletion at the front end in the Queue (NORMAL DEQUEUE OPERATION)
int DeQueueF(struct DEQueue *q)
{
    if(IsEmpty(q))
    {
        printf("There is no elemet in the Queue\n");
        return -1;
    }
    else
    {
         q->front++;
         int val=q->arr[q->front];
        return val;

    }
}

// Displaying the DEQueue element
void Display(struct DEQueue *q)
{
    int i=0;
    while(i<=(q->rear))
    {
        printf("Element:%d\n",q->arr[i]);
        i++;
    }
}


int main()
{
struct DEQueue *q=(struct DEQueue *) malloc(sizeof(struct DEQueue));
q->size=5;
q->front=q->rear=-1;
q->arr=(int *)malloc(q->size*sizeof(int));

EnQueueR(q,15);
EnQueueR(q,19);
EnQueueR(q,25);
EnQueueR(q,95);
EnQueueR(q,55);


Display(q);
printf("Element is DeQueued at the front:%d\n",DeQueueF(q));
Display(q);
printf("Element is DeQueued at the rear:%d\n",DeQueueR(q));
Display(q);

return 0;
}