// 백준 6086번
// 최대 유량
// C++

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Flow
{
private:
    vector<vector<int>> adj;
    vector<vector<int>> capacity;
    vector<vector<int>> r;

    int N;
    int start;
    int end;

public:
    Flow(int N) : N(N)
    {
        adj.resize(N);
        capacity.resize(N);
        start = ChangeAlp('A');
        end = ChangeAlp('Z');
    }
    
    int ChangeAlp(char Alp){
        return Alp - 'A';
    }

    void InputEdge(char P, char C, int w)
    {
        int p = ChangeAlp(P);
        int c = ChangeAlp(C);

        adj[p].push_back(c);
        adj[c].push_back(p);
        capacity[p].push_back(w);
        capacity[w].push_back(0);
    }

    vector<int> DoBFS()
    {
        int bottleneck;
        vector<int> p(N); // 부모
        vector<int> d(N + 1);
        vector<bool> visited(N + 1, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int n : adj[u])
            {
                if (!visited[n] && (capacity[u] > 0))
                {
                    visited[n] = true;
                    d[n] = d[u] + 1;
                    p[n] = u;
                    q.push(n);
                }
            }
        }

        DoFlowConservation(p);
    }

    void DoFlowConservation(vector<int> &p)
    {
    }
};

int main()
{
    int N, s, t;
    cin >> N;

    Flow flow(N);
    for (int i = 0; i < N; i++)
    {
        char p, c;
        int w;

        cin >> p, c, w;
        flow.InputEdge(p, c, w);
    }

    flow.DoBFS();

    return 0;
}