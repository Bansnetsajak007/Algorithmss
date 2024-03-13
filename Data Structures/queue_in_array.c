#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int back;
    int *arr;
};

int isEmpty(struct Queue * ptr){
    if(ptr->front == ptr->back){
        return 1;
    }

    else{
        return 0;
    }
}

int isFull(struct Queue * ptr){
    if(ptr->back == ptr->size -1){
        return 1;
    }

    else{
        return 0;
    }
}

void Enqueue(struct Queue *ptr, int value){
    if(!isFull(ptr)){
        ptr->back++;  //linear increament
        ptr->arr[ptr->back] = value;
        printf("The enqueued element is %d\n", value);
    }

    else{
        printf("Queue is full cant enqueue element\n");
    }
}

void Dequeue(struct Queue *ptr){
    int a;
    if(!isEmpty(ptr)){
        ptr->front++;
        a= ptr->arr[ptr->front];
        printf("The dequeued element is %d\n", a);
    }

    else{
        printf("Cannot dequeue element form and empty queue\n");
    }
}

void peek(struct Queue* ptr, int position){
    int value;
    if(ptr->back- position+1 <0){
        printf("invalid Queue operation\n");
    }

    else{
        value= ptr->arr[ptr->back -position+1];
        printf("The peeked value is %d", value);
    }
}




int main(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    int size=10;
    int front= -1;
    int back = -1;
    int *arr = (int *) malloc(q->size * sizeof(int));  //main Datastructure is this (QUEUE WILL BE IMPLEMENTED ON TOP OF THIS)


//initializing structure variables
    q->size = size;
    q->front = front;
    q->back = back;
    q->arr = arr;
    
    // q->arr[0] = 5;
    // q->back+=1;
    // q->arr[1] = 10;
    // q->back+=1;
    // q->arr[2] = 100;
    // q->back+=1;
    // q->arr[3] = 20;
    // q->back+=1;
    // q->arr[4] = 20;
    // q->back+=1;

    Enqueue(q, 89);  //first element to enter in the queue and also it will be first to be out
    Enqueue(q, 69);
    Enqueue(q, 49);
    Enqueue(q, 99);
    Enqueue(q, 4);

    Dequeue(q);
  
    peek(q,5);
    free(q);
    free(arr);
    return 0;
}