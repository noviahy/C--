// 백준 15650번
// 백트래킹
// C++

#include <iostream>
#include <vector>
using namespace std;

class BackTracking
{
private:
    int n, m;
    vector<int> per;

public:
    BackTracking(int n, int m)
        : n(n), m(m)
    {
        per.reserve(m);
    }

    void doBack(int start, int len)
    {
        if (len == m)
        {
            string s;
            for (int i : per)
                s += to_string(i) + " ";
            cout << s << '\n';

            return;
        }

        for (int i = start; i <= n; i++)
        {
            per.push_back(i);
            doBack(i + 1, len + 1);

            per.pop_back();
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    BackTracking B(N, M);
    B.doBack(1, 0);

    return 0;
}