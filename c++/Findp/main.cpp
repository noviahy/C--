#include "Rectangle.h"

int main() {
    // (1, 1)과 (5, 5)로 좌표를 초기화한 Rectangle 객체 생성
    Rectangle rec(1, 1, 5, 5);
    
    // 사각형 정보 출력
    rec.ShowRecInfo();
    
    return 0;
}
