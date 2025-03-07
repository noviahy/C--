#include "retangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
    : upLeft(x1, y1), lowRight(x2, y2)
{
    // 좌 상단 좌표가 우 하단 좌표보다 큰 경우 처리
    if (upLeft.GetX() > lowRight.GetX() || upLeft.GetY() > lowRight.GetY())
    {
        std::cout << "좌표 설정 오류! 초기화합니다." << std::endl;
        upLeft = Point(0, 0);     // 기본값으로 초기화
        lowRight = Point(0, 0);
    }
}

void Rectangle::ShowRecInfo() const
{
    std::cout << "좌 상단: [" << upLeft.GetX() << ", " << upLeft.GetY() << "]" << std::endl;
    std::cout << "우 하단: [" << lowRight.GetX() << ", " << lowRight.GetY() << "]" << std::endl;
}
