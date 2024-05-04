#include<stdio.h>

void printArray(int* A, int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int* A, int n){
    int temp;
    int isSorted=0;
    for(int i=0;i<n-1;i++){
        printf("Working on pass number %d\n", i+1);
        isSorted=1;
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                temp= A[j];
                A[j] = A[j+1];
                A[j+1]= temp;
                isSorted=0;
            }
        }
        if(isSorted){
            return;   //indicates function has done working and should return nothing
            //indicated end of function
        }
    }
}


int main(){
    // int A[]= {12,69,1,7,4,5};
    int A[]= {5,2,8,7,1};
    // int A[]={1,2,3,4,5};
    // int A[] = {1,3,2,6,4};
    int n = sizeof(A) / sizeof(A[0]);

    printArray(A,n);
    bubbleSort(A,n);
    printArray(A,n);
        return 0;
}