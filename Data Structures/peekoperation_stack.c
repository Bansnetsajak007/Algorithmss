#include <stdio.h>
#include <stdlib.h>

struct stack {
  int size;
  int top;
  int *arr;
};

void push(struct stack *ptr, int value) {

    ptr->top++;
    ptr->arr[ptr->top] = value;
}


int peek(struct stack* ptr, int position){
    if(ptr->top- position+1 <0){
        printf("invalid stack operation\n");
    }

    else{
        return ptr->arr[ptr->top -position+1];
    }
}


int main() {
//   struct stack *s = (struct stack *)malloc(sizeof(struct stack));
  struct stack *s;
  s->size = 5;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));

  
  push(s, 52);
  push(s, 9);
  push(s, 17);
  push(s, 7);
  push(s, 23);

  int result= peek(s,3);
  peek(s,6);
  printf("The peeked value is %d\n",result);

  return 0;
  }