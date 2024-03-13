#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maxmimum(int* array, int n){
    int max=0,i;

    for(i=0;i<n;i++){
        if(array[i]>max){
            max = array[i];
        }
    }

    return max;

}

void countSort(int* A, int n){
    int i,j;
    int max = maxmimum(A,n);

    //crearting new array name count
    int* count = (int*) malloc((max + 1) * sizeof(int));

    //initializing all the elements of count to 0
    for(i=0;i<max+1;i++){
        count[i] = 0;
    }

    //incrementing the corresponding index of 
    for(i=0;i<n;i++){
        count[A[i]] = count[A[i]] + 1;
    }

    i=0;
    j=0;

    while(i<= max){
        if(count[i]>0){
            A[j] = i;  //updating our main array in sorted form (putting index in array)
            count[i] = count[i] -1; 
            j++;
        }
        else{
            i++;
        }
    } 
}



int main(){

    int A[] = {100,2,69,40,1,9,7,6};
    int size = sizeof(A)/sizeof(A[0]);

    printArray(A,size);
    countSort(A,size);
    printArray(A,size);

    return 0;
}