#include <stdio.h>

#define SIZE 4

int main() {
    int b[] = { 10,20,30,40 };
    int* bPtr = b;

    for (int i = 0; i < SIZE; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);            // �迭�� ��� ���
        printf("*(b + %d) = %d\n", i, *(b + i));    // �����͸� �̿��� �迭�� ��� ���
        printf("bPtr[%d] = %d\n", i, bPtr[i]);      // ������ �迭�� ��� ���
        printf("*(bPtr + %d) = %d\n\n", i, *(bPtr + i)); // �����͸� �̿��� ������ �迭�� ��� ���
    }

    return 0;
}