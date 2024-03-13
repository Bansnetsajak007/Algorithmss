#include<stdio.h>


void display(int array[],int n){
    for (int i = 0; i < n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}

//main logic to performe insertion in array
int insert(int array[],int array_size,int element,int index,int capacity){
    if(array_size>=capacity){
        return -1;
    }


        for(int i = array_size-1;i>=index;i--){
            // array[i]=array[i+1];    //prints 0 cuz i+1 is not initialized  //code for deletion arr[i] = arr[i + 1];
            array[i+1]= array[i];
        }
        array[index]= element;
 
    return 1;
}



int main(){
    int array[50]= {2,6,8,10};
    int u_size=4,element=100,index=2;

    display(array,u_size);

    insert(array,u_size,element,index,50);


    u_size +=1;

    display(array,u_size);

    return 0;
}