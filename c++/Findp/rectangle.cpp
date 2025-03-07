#include "Rectangle.h"
#include <iostream>

// 생성자 구현
Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : x1(x1), y1(y1), x2(x2), y2(y2) {}

// 사각형 정보 출력 함수 구현
void Rectangle::ShowRecInfo() const {
    std::cout << "Rectangle corners: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")\n";
}
