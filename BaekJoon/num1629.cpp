// 백준 2252번
// Divide_Conquer
// C++

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

long long divide(long long a, long long num, long long q)
{
    if (num == 0)
        return 1;

    else if (num % 2 == 0)
        return divide(a, num / 2, q) * divide(a, num / 2, q) % q;

    else if (num % 2 == 1)
        return a * divide(a, num - 1, q) % q;
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;

    long long result = divide(a, b, c);
    cout << result;

    return 0;
}