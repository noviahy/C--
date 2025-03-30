#include "class.h"

int main()
{
    Carculator cal;

    std::cout << " 3.2 + 2.4 = " << cal.Plus(3.2, 2.4) << std::endl;
    std::cout << " 3.5 / 1.7 = " << cal.Div(3.5, 1.7) << std::endl;
    std::cout << " 2.2 - 1.5 = " << cal.Sub(2.2, 1.5) << std::endl;
    std::cout << " 4.9 / 1.2 = " << cal.Div(4.9, 1.2) << std::endl;
    cal.ShowOpCount();
    return 0;
}//Windows에서 MinGW를 사용해 컴파일할 때 발생하는 오류. 콘솔 애플리케이션을 빌드하려고 할 때 발생한다.
// main함수 대신 WinNain을 찾으려고 해서 발생한다. vsc가 이닌 vs에서는 오류가 나지 않으며
//해결 방법을 찾지 못했다