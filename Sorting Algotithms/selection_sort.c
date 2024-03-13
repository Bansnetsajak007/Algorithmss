#include<stdio.h>

void printArray(int* A, int n){
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int* A, int n){
    int min,temp,i,j;

    for(i=0;i<n-1;i++){
        min = i;

        for(j=i+1;j<n;j++){
            if(A[min]>A[j]){
                min = j;
            }

        }
            //placing the element at correct index (interchanging elementss)
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
    }

}


int main(){
    // int A[]= {12,69,1,7,4,5};
    int A[]= {100,23,85,2,45,1,0,96,3,4,7,6};
    // int A[]={1,2,3,4,5};
    // int A[] = {1,3,2,6,4};
    // int A[] = {8,0,7,1,3};

    int n = sizeof(A) / sizeof(A[0]);

    printArray(A,n);
    selectionSort(A,n);
    printArray(A,n);
        return 0;
}