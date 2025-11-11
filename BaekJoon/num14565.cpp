// 백준 14565번
// 역원(Inverse) 구하기
// C++

#include <iostream>
#include <cstring>

using namespace std;

class Inverse
{
private:
    long long N, A;

public:
    Inverse(long long N, long long A) : N(N), A(A) {}

    long long findadd() // 덧셈역
    {
        return ((-A % N) + N) % N;
    }

    long long findmul() // 곱셈역
    {
        long long x, y;
        long long g = extended_gcd(A, N, x, y);

        // 곱셈역에서 역원이 존재하려면 gcd(A, N) == 1이어야 함
        if (g != 1)
            return -1;

        // x가 음수일시 양수로 바꿔줌
        return (x % N + N) % N;
    }

    // 확장 유클리드 알고리즘
    long long extended_gcd(long long a, long long n, long long &x, long long &y)
    {
        if (n == 0) // 나머지 0
        {
            x = 1;
            y = 0;
            return a;
        }

        long long x1, y1;                             // 결과 받을 임시 변수
        long long g = extended_gcd(n, a % n, x1, y1); // 재귀 호출

        x = y1;
        y = x1 - (a / n) * y1;

        return g;
    }
};

int main()
{
    long long N, A;
    cin >> N >> A;

    Inverse in(N, A); // 생성자

    cout << in.findadd() << " " << in.findmul(); // 덧셈역, 곱셈역 출력
    return 0;
}