//Array implementation

#include <stdio.h>
#include <stdlib.h>

struct stack {
  int size;
  int top;
  int *arr;
};

int isEmpty(struct stack *ptr) {
  if (ptr->top == -1) {
    return 1; // 1 indicates True
  }

  else {
    return 0; // 0 indicates False
  }
}

int isFull(struct stack *ptr) {
  if (ptr->top == ptr->size - 1) {
    return 1;
  }

  else {
    return 0;
  }
}

void push(struct stack *ptr, int value) {
  if (isFull(ptr)) {
    printf("Stack overflow\n");
  }

  else {
    ptr->top++;
    ptr->arr[ptr->top] = value;
  }
}

int pop(struct stack *ptr) {
  int temp = 0;
  if (isEmpty(ptr)) {
    printf("Stack underflow");
  }

  else {
    temp = ptr->arr[ptr->top];
    ptr->top--;
  }
  return temp;
}

int top(struct stack* ptr){

  return ptr->arr[ptr->top];

}

int bottom(struct stack* ptr){

  return ptr->arr[0];
  
}


int main() {
  struct stack *s;
  s->size = 5;
  s->top = -1;
  s->arr = (int *)malloc(s->size * sizeof(int));

  push(s, 5);  //bottom most element of stack 
  push(s, 8);
  push(s, 12);
  push(s, 17);
  push(s, 23); //topmost element of stack



  printf("The top most element od stack is %d\n", top(s));

  printf("The bottom most element od stack is %d", bottom(s));


  return 0;
}