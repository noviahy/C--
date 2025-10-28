// 백준 2252번
// Dijkstra
// C++

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Dijkstra
{
private:
    vector<vector<int>> adj;
    vector<vector<int>> weight;
    int N;
    int start;

public:
    Dijkstra(int n, int s)
        : N(n), start(s)
    {
        adj.resize(N + 1);
        weight.resize(N + 1);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(v);
        weight[u].push_back(w);
    }

    void DoDijkstra()
    {
        vector<int> D(N + 1, INT_MAX);
        D[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            auto [dist, u] = pq.top();
            pq.pop();

            if (dist > D[u])
                continue;

            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                int w = weight[u][i];
                if (D[v] > D[u] + w)
                {
                    D[v] = D[u] + w;
                    pq.push({D[v], v});
                }
            }
        }

        print_D(D);
    }

    void print_D(vector<int> &D)
    {
        for (int i = 1; i <= N; i++)
        {
            if (D[i] != INT_MAX)
                cout << D[i] << endl;
            else
                cout << "INF" << endl;
        }
        cout << endl;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    int start;
    cin >> start;

    Dijkstra Dij(V, start);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Dij.addEdge(u, v, w);
    }

    Dij.DoDijkstra();
    return 0;
}