// #include<stdio.h>

// void printArr(int arr[], int size){
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d\t", arr[i]);
//     }
    
// }

// int quick(int arr[]) {
//     int left[] = {0};
//     int middle[] = {0};
//     int right[] = {0};
//     int pivot = sizeof(arr) / 2;
//     int size = sizeof(arr) / sizeof(int);

//     //base case
//     if(sizeof(arr) <= 1) return arr;

//     //array scanning
//     for (int i = 0; i < size; i++) {
//     if(pivot > arr[i])
//         left[i] = arr[i];
//     else if (pivot < arr[i]) {
//         right[i] = arr[i];
//     } else{
//         middle[i] = arr[i];
//     }
//     } 

//     return quick(left) + middle + quick(right);
// }

// int main(){
//     int arr[] = {64,24,12,80,97,11};
//     int size = sizeof(arr) / sizeof(int);

//     int arr1[] = quick(arr);

//     printArr(arr1,size);
    
//     return 0;
// }

#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 24, 12, 80, 97, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArr(arr, size);

    return 0;
}
