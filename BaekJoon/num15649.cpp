// 백준 15649번
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
    bool visited[9];

public:
    BackTracking(int n, int m)
        : n(n), m(m)
    {
        per.reserve(m);
        fill(visited, visited + 9, false);
    }

    void doBack(int len)
    {
        if (len == m)
        {
            string s;
            for (int i : per)
                s += to_string(i) + " ";
            cout << s << '\n';

            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            visited[i] = true;

            per.push_back(i);
            doBack(len + 1);

            per.pop_back();
            visited[i] = false;
        }
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    BackTracking B(N, M);
    B.doBack(0);

    return 0;
}