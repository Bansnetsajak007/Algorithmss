#include<stdio.h>

int li_search(int arr[],int n){

    for (int i = 0; i < 4; i++)   {

        if(arr[i]==n){
            return("%d\n",arr[i]);
        }

}

    return 0;

}

int main(){

    int array[]={10,2,42,56,20},number=100;

   int result= li_search(array,number);

   printf("%d",result);

    return 0;
}