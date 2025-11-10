// 백준 14565번
// 역원(Inverse) 구하기
// C++

#include <iostream>
#include <cstring>

using namespace std;

class Invserse
{
private:
    int N, A;

public:
    Invserse(int N, int A) : N(N), A(A) {}

    int findadd() // 덧셈역
    {
        return (A - N) % N;
    }

    int findmul() // 곱셈역
    {
        int x, y;
        int g = extended_gcd(A, N, x, y);

        // 곱셈역에서 역원이 존재하려면 gcd(A, N) == 1이어야 함
        if (g != 1)
            return -1;

        // x가 음수일시 양수로 바꿔줌
        return (x % N + N) % N;
    }

    // 확장 유클리드 알고리즘
    int extended_gcd(int e, int b, int &x, int &y)
    {
        if (b == 0) // 나머지 0
        {
            x = 1;
            y = 0;
            return e;
        }

        int x1, y1; // 결과 받을 임시 변수
        int g = extended_gcd(b, e % b, x1, y1); // 재귀 호출

        x = y1;
        y = x1 - y1 * (e / b);

        return g;
    }
};

int main()
{
    int N, A;
    cin >> N >> A;

    Invserse in(N, A); // 생성자

    cout << in.findadd() << " " << in.findmul(); // 덧셈역, 곱셈역 출력
    return 0;
}