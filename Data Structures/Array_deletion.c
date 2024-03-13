#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    printf("\n");
}

//main logic to performe deletion in array
void pop(int arr[], int index)
{
    for (int i = index; i < 4; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{

    int array[10] = {90, 34, 56, 78};
    // int index=0;
    int size = 4;

    display(array, size);

    pop(array, 3);

    size -= 1;
    display(array, size);
    return 0;
}