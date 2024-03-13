//sorting two different arrays into same using merge sort 
// both the arrays must be in sorted order

#include<stdio.h>


void merge_sort(int* A, int*B, int*C,int x, int y, int t ){
    int i,j,k;
    i=j=k=0;

    while(i<x && j<y){
        if(A[i]>B[j]){
            C[k] = B[j];
            j++,k++;
        }

        else{
            C[k] = A[i];
            i++,k++;
        }

       
    }

        while(i<x){
            C[k] = A[i];
            i++,k++;
        }

        while(j<y){
            C[k] = B[j];
            j++,k++;
        } 


    for ( k = 0; k < t; k++)
    {
        printf("%d ", C[k]);
    }

}


int main(){
    int A[] = {3,8,69};
    int B[] = {1,2};
    // int A[] = {5,8,7,9,10,23,45};
    // int B[] = {1,2,9,6,5,8,100,67,45};

    int a_size = sizeof(A) / sizeof(A[0]);
    int b_size = sizeof(B) / sizeof(B[0]);
    int n = a_size + b_size;
    int C[n];


    merge_sort(A,B,C,a_size,b_size,n);


    return 0;
}