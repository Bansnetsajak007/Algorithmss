// #include <stdio.h>
// #include <stdlib.h>

// struct stack {
//   int size;
//   int top;
//   char *arr;
// };

// int isEmpty(struct stack *ptr) {
//   if (ptr->top == -1) {
//     return 1; // 1 indicates True
//   }

//   else {
//     return 0; // 0 indicates False
//   }
// }


// void push(struct stack *ptr,char array[]) {
//     int i=0;
//     while(array[i]!= '\0'){
//         if(array[i]=='('){
//             ptr->top+=1;
//             ptr->arr[ptr->top]= '(';
//             printf("Opening Parenthesis is sucessfully passed in stack\n");
//         }
//         i++;
//     }

// }

// int pop(struct stack *ptr,char array[]){
//   char temp;
//   int i=0;
//   if(isEmpty(ptr)){
//     printf("Expression is unbalanced\n");
//   }

//   else{
//     while(array[i]!= '\0'){
//         if(array[i]==')'){     
//         temp = ptr->arr[ptr->top];
//         ptr->top--;
//         printf("closing Parenthesis is sucessfully poped from stack\n");
//         }
//         i++;
//       return temp;
//     }

//   }
  
// }

// void EOE(struct stack *ptr){
//   if(isEmpty(ptr)){
//     printf("At the end of expression stack is empty so expression is balanced\n");
//   }
//   else{
//     printf("Expression is not balanced\n");
//   }
// }

// int main() {

//     char str[]= {'(','1','+',')','(','(','\0'}; //expression 
//   struct stack *s;
//   s->size = 10;
//   int topp=-1;
//   s->arr = (char *)malloc(s->size * sizeof(char));

    

//     push(s,str);
//     char ch=pop(s,str);

//     printf("The poped thing is %c", ch);
//     // EOE(s);

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); 
        }
    }
 
    if(isEmpty(sp)){
        return 1;  //means balanced expression
    }
    else{
        return 0;
    }
    
}
int main()
{
    // char * exp = "((8)(*--$$9))";
    char * exp = "(((((((((((((8)(*--$$9)))))))))))))";
    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}
