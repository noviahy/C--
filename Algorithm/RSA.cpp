#include <iostream>
using namespace std;

// ---------------------------
// modpow: 재귀 버전 빠른 거듭제곱
// a^b % n 계산
// ---------------------------
int modpow(int a, int b, int n) {
    if (b == 0) return 1;  // b==0이면 결과는 1
    if (b % 2 == 0) {      // b가 짝수
        int d = modpow(a, b / 2, n);
        return (1LL * d * d) % n;
    } else {                // b가 홀수
        int d = modpow(a, b - 1, n);
        return (1LL * a * d) % n;
    }
}

// ---------------------------
// 확장 유클리드
// ax + by = gcd(a,b) 풀기
// ---------------------------
int egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int g = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// ---------------------------
// 모듈러 역원
// a*d ≡ 1 (mod mod)
// ---------------------------
int modinv(int a, int mod) {
    int x, y;
    int g = egcd(a, mod, x, y);
    if (g != 1) return -1;
    int res = x % mod;
    if (res < 0) res += mod;
    return res;
}

int main() {
    // RSA 예제 (작은 소수)
    int p = 61, q = 53;
    int n = p * q;          // 공개키 modulus
    int phi = (p - 1) * (q - 1);

    int e = 17;             // 공개키 지수
    int d = modinv(e, phi); // 개인키

    int msg = 65;           // 평문

    int enc = modpow(msg, e, n); // 암호화
    int dec = modpow(enc, d, n); // 복호화

    cout << "enc = " << enc << "\n";
    cout << "dec = " << dec << "\n";
}
