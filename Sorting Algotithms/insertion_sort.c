#include<stdio.h>

void printArray(int* A, int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int* A, int n){
    int key,j;
    for(int i=1;i<=n-1;i++){
        key = A[i];
        j = i-1;

        while(j>=0 && A[j]>key){
            A[j+1] = A[j];  //moving particular element onestep towards right
            j--;
        }

        A[j+1] = key;  //placing the element(key) in correct position
    }
}


int main(){
    // int A[]= {12,69,1,7,4,5};
    int A[]= {100,23,85,2,45,1,0,96,3,4,7,6};
    // int A[]={1,2,3,4,5};
    // int A[] = {1,3,2,6,4};
    // int A[] = {2,1,3,4,7};

    int n = sizeof(A) / sizeof(A[0]);

    printArray(A,n);
    insertionSort(A,n);
    printArray(A,n);
        return 0;
}