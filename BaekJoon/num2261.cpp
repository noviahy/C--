// 백준 2261번
// 가장 가까운 두 점
// C++

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Divde_ConQuer
{
private:
    int numDot;
    vector<pair<int, int>> dot;
    int shortest;

public:
    Divde_ConQuer(int N)
        : numDot(N) {}

    void addPoint(int x, int y)
    {
        dot.push_back(make_pair(x, y));
    }

    void sortDot()
    {
        sort(dot.begin(), dot.end());
    }

    int doDC(int begin, int end)
    {
        if (begin + 1 == end)
            return doCalculate(begin, end);
        else{
            int left = doDC(begin, (begin+end)/2);
            int right = doDC((begin+end)/2, end);
            shortest = min(left, right);
        }
        
    }

    int doCalculate(int i, int j)
    {
        int dx = dot[i].first - dot[j].first;
        int dy = dot[i].second - dot[j].second;
        return dx * dx + dy * dy;
    }
};

int main()
{
    int N;
    cin >> N;

    Divde_ConQuer dc(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        dc.addPoint(x, y);
    }

    dc.sortDot();
    cout << dc.doDC(0, N-1);

    return 0;
}