//binary search in C

#include<stdio.h>

int binary_search(int array[],int n,int number){
    int l=0,h=n-1,m;

    while(l<=h){
        m=(l+h)/2;

        if(array[m]==number){
            return m;
        }
        if(array[m]<number){
            l=m;
        }

        else{
            h=m;
        }
    }
    return -1;
}




int main(){

    int array[20]={2,6,10,13,17,90},t_size=6;
    int element= 6;

    int result=binary_search(array,t_size,element);

    if (result==-1){
        printf("Element is not present in array");
    }

    else{
        printf("The element %d was found at index %d",element,result);
    }

    return 0;
}