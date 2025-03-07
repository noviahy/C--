#include <stdio.h>

#define SIZE 4

int main() {
    int b[] = { 10,20,30,40 };
    int* bPtr = b;

    for (int i = 0; i < SIZE; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);            // 배열의 요소 출력
        printf("*(b + %d) = %d\n", i, *(b + i));    // 포인터를 이용한 배열의 요소 출력
        printf("bPtr[%d] = %d\n", i, bPtr[i]);      // 포인터 배열의 요소 출력
        printf("*(bPtr + %d) = %d\n\n", i, *(bPtr + i)); // 포인터를 이용한 포인터 배열의 요소 출력
    }

    return 0;
}