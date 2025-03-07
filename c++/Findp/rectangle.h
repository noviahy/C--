#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    int x1, y1, x2, y2;  // 사각형의 좌표

public:
    // 생성자: (x1, y1)과 (x2, y2) 좌표를 받아 초기화
    Rectangle(int x1, int y1, int x2, int y2);

    // 사각형 정보 출력 함수
    void ShowRecInfo() const;
};

#endif
