#include<stdio.h>


void merge_array(int* A, int* B, int a_size,int b_size,int t_size){

    int C[t_size],i,j,k;

    //scanning array A
    for (i = 0; i < a_size; i++){
        C[i] = A[i];

    }

    //scannong array B
    for (j = 0; j < b_size; j++){
        C[a_size + j] = B[j];

    }    

    //printing the final mergerd array
    for (k = 0; k < t_size; k++){
        printf("%d\t", C[k]);

    }

}




int main(){
    // int A[] = {5,8,7,9};
    // int B[] = {1,2,9,6,5,8};

    int A[] = {5,8,7,9,10,23,45};
    int B[] = {1,2,9,6,5,8,100,67,45};

    int a_size = sizeof(A) / sizeof(A[0]);
    int b_size = sizeof(B) / sizeof(B[0]);
    int n = a_size + b_size;


    merge_array(A,B,a_size,b_size,n);


    return 0;
}