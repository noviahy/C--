// 백준 1005번
// DAG
// C++

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// #include <climits>
using namespace std;

class DAG
{
private:
    vector<vector<int>> adj;
    vector<int> indegree;
    vector<int> time;
    int N;

public:
    DAG(int n)
        : N(n)
    {
        adj.resize(N + 1);
        time.resize(N + 1);
        indegree.resize(N+1);
    }

    void setTime(int i, int t)
    {
        time[i] = t;
    }

    void addEdge(int s, int e)
    {
        adj[s].push_back(e);
        ++indegree[e];
    }

    void DoDAG(int E)
    {
        vector<int> D(N + 1, 0);
        queue<int> Q;

        for (int i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
            {
                Q.push(i);
                D[i] = time[i];
            }
        }

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for (int n : adj[u])
            {
                D[n] = max(D[n], D[u] + time[n]);
                -- indegree[n];
                if (indegree[n] == 0)
                    Q.push(n);
            }
        }

        cout << D[E] << endl;
    }
};

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N, M, E;
        cin >> N >> M;
        DAG D(N);

        for (int j = 1; j <= N; j++)
        {
            int t;
            cin >> t;
            D.setTime(j, t);
        }

        for (int j = 0; j < M; j++)
        {
            int s, e;
            cin >> s >> e;
            D.addEdge(s, e);
        }
        cin >> E;
        D.DoDAG(E);
    }

    return 0;
}