//using pointers

#include<stdio.h>

void li_search(int *ptr,int n){
    for (int i = 0; i < 4; i++)

    {
        if(*(ptr)==n){
            printf("%d\n",*(ptr));
        }       
        ptr++;


    }

}


int main(){

    int array[]={10,2,42,56,20},number=2;

    li_search(array,number);

    return 0;
}