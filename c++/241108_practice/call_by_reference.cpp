#include <iostream>

void SwapPointer(int **ptr1, int **ptr2)
{
    int *a = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = a;
}

int main()
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    std::cout << *ptr1 <<" "<< *ptr2 << std::endl;

    SwapPointer(&ptr1, &ptr2);

    std::cout << *ptr1 <<" "<< *ptr2 << std::endl;
} // 책 80권 3번째 문제, 이게 의도한게 맞는건지 모르겠다