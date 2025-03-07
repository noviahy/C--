#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int square_add(int a, int b) {
    int result;
    result = (a * a) + (b * b);
    return result;
}

int main() {
    int num1, num2, result;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    result = square_add(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}