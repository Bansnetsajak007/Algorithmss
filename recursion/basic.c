#include<stdio.h>

int factorial(int n) {
    if(n == 0 || n== 1) {

    } else {
        return (n * factorial(n - 1));
    }
}


int main() {
    int number = 5;

    int result = factorial(number);

    printf("The factorial of %d is %d", number, result);
    return 0;
}