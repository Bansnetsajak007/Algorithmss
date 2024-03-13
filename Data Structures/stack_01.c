//implementing stack using Array

#include<stdio.h>
#include<stdlib.h>


    struct stack {
        int size;
        int top;
        int * arr;
    };


int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;  //1 indicates True
    }

    else{
        return 0;  //1 indicates False
    }
}

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }

    else{
        return 0;
    }
    
}

int main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    //initializing array manuallly to check isEmpty and isfulll function
    // printf("enter the emements to full stack");
    // for(int i=0;i<(s->size);i++){
    //     scanf("%d", &s->arr[i]);
    //     s->top+=1; 
    // }


    s->arr[0] = 5;
    s->top+=1;
    s->arr[1] = 10;
    s->top+=1;
    s->arr[2] = 15;
    s->top+=1;
    s->arr[3] = 20;
    s->top+=1;
    s->arr[4]= 25;
    s->top+=1;

    if(isFull(s)){
        printf("stack is Full");
    }

    else{
        printf("stack is not full");
    }    

    return 0;
}