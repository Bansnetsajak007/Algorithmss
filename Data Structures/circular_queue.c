//main concept here is circular increament not traditional linear increament

#include<stdio.h>
#include<stdlib.h>

// Queue ADT
struct Queue{
    int size;
    int front;
    int back;
    int *arr;
};


void Enqueue(struct Queue *ptr, int value){
    if((ptr->back+1)% (ptr->size)== ptr->front){
        printf("Cannot enqueue element!");
    }

    else{
        ptr->back= (ptr->back+1)% (ptr->size);
        ptr->arr[ptr->back]= value;
        printf("The enqueued element in stack is %d\n", value);
    }
}

void Dequeue(struct Queue *ptr){
    int a=-1;

    if(ptr->front == 0 && ptr->back==0){  //this condition indicates empty queue
        printf("Cant Dequeue element from queue");
    }

    else{
        ptr->front = (ptr->front+1)% (ptr->size);
        a= ptr->arr[ptr->front];
        printf("The dequeued element in queue is %d\n", a);
    }
}

int main(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    int size=4;
    int front=0;
    int back =0;
    int *arr = (int *) malloc(q->size * sizeof(int));


    q->size = size;
    q->front = front;
    q->back = back;
    q->arr = arr;


    Enqueue(q,69);
    Enqueue(q,14);
    Enqueue(q,20);
    

    Dequeue(q);
    Dequeue(q);
    Dequeue(q);
    

    Enqueue(q,999);
    Enqueue(q,777);
    Enqueue(q,888);




    return 0;
}