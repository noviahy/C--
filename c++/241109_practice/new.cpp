#include <iostream>

struct Point
{
    int *xpos;
    int *ypos;
};

Point &PntAdder(const Point &p1, const Point &p2)
{
    static Point result;
    result.xpos = new int;
    result.ypos = new int;

    *result.xpos = *p1.xpos + *p2.xpos;
    *result.ypos = *p1.ypos + *p2.ypos;
    return result;
}

int main()
{
    Point P1, P2, P3;

    P1.xpos = new int;
    P1.ypos = new int;
    P2.xpos = new int;
    P2.ypos = new int;
    P3.xpos = new int;
    P3.ypos = new int;

    std::cout << "Enter P1 xpos and ypos: ";
    std::cin >> *P1.xpos;
    std::cin >> *P1.ypos;

    std::cout << "Enter P2 xpos and ypos: ";
    std::cin >> *P2.xpos;
    std::cin >> *P2.ypos;

    P3 = PntAdder(P1, P2);

    std::cout << "P3 xpos: " << *P3.xpos << ", P3 ypos: " << *P3.ypos << std::endl;

    delete P1.xpos;
    delete P1.ypos;
    delete P2.xpos;
    delete P2.ypos;
    delete P3.xpos;
    delete P3.ypos;

    return 0;
}