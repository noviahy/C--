#include <iostream>

int main()
{
    const int num = 12;
    const int *point1 = &num;
    const int *const &point2= point1;

    std::cout<<*point2<<std::endl;
}// 책 90p 문제 02-2