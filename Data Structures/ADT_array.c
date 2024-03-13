#include<stdio.h>
#include<stdlib.h>
 
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;  //points or holds addreass of an integer variable
};
 
void createArray(struct myArray * a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
 
    a->total_size = tSize;   //initilizing myArray's total_size  of Structure myArray via pointer

    a->used_size = uSize;   //initilizing myArray's used_size of Structure myArray via pointer

    a->ptr = (int *)malloc(tSize * sizeof(int));    //requesting memory from the heap and giving base address to ptr(integer pointerr)
}
 
void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
 
void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}
 
int main(){
    struct myArray marks;
    createArray(&marks, 10, 4);
    printf("We are running setVal now\n");
    setVal(&marks);
 
    printf("We are running show now\n");
    show(&marks);
 
    return 0;
}