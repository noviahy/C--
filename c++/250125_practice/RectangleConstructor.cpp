#include "retangle.h"

int main()
{
   Rectangle rec(1, 1, 5, 5);
    rec.ShowRecInfo();
    return 0;
} // 문제점: x, y값이 0~100사이가 아니다
// 좌 상단의 좌표 값ㄱ이 우 하단의 좌표 값보다 클 경우의 오류를 해결하지 못한다