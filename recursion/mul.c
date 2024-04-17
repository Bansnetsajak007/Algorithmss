#include <stdio.h>

int multiply(int x, int y) {
    if (y == 0)
        return 0;
    return x + multiply(x, y - 1);
}

int main() {
    int x = 5, y = 4;
    printf("Product of %d and %d is %d\n", x, y, multiply(x, y));
    return 0;
}
