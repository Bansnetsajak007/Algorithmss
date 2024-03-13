#include<stdio.h>

int func1(int array[] , int size){
    int sum=0;
    int product=1;

    for (int i = 0; i < size; i++){
    
        sum =sum + array[i];
    }
    
    for (int i = 0; i < size; i++){
    
        product =product * array[i];
    }

    printf("The sum and product of array are: %d %d\n",sum,product);

}


int main(){
    int arr[]={2,4,6,1,2,3,1,2,3,4};

    int length= (sizeof(arr)/4);
    // int length= (sizeof(arr));

     func1(arr,length);

    printf("%d",length);

     return 0;
}