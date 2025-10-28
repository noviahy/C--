// 백준 2252번
// Kahn's Algorithm
// C++

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Kahns
{
private:
    vector<vector<int>> adj;
    vector<int> indegree;
    int N;

public:
    Kahns(int n)
        : N(n)
    {
        adj.resize(N + 1);
        indegree.resize(N + 1, 0);
    }

    void addEdge(int s, int e)
    {
        adj[s].push_back(e);
        ++indegree[e];
    }

    void DoKahns()
    {
        vector<int> order;
        queue<int> q;

        for (int i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u])
            {
                --indegree[v];
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        print_order(order);
    }

    void print_order(vector<int>& order)
    {
        for (int v : order)
            cout << v << " ";
        cout << endl;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Kahns K(N);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        K.addEdge(s, e);
    }

    K.DoKahns();
    return 0;
}