// 백준 11404번
// Floyd-Warshall
// C++

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Warshall
{
private:
    vector<vector<long long>> dist;
    int N;
    const long long INF = 1e15;

public:
    Warshall(int n) : N(n)
    {
        dist.resize(N + 1, vector<long long>(N + 1, INF));

        // 자기 자신으로 가는 거리는 0
        for (int i = 1; i <= N; i++)
            dist[i][i] = 0;
    }

    void addEdge(int u, int v, int w)
    {
        dist[u][v] = min(dist[u][v], (long long)w); // 여러 간선 중 최소값
    }

    void DoWarshall()
    {
        for (int k = 1; k <= N; k++)
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    void print_result()
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] == INF)
                    cout << "0 "; // 백준 11404 문제 기준: 도달 불가 → 0 출력
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Warshall W(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        W.addEdge(u, v, w);
    }

    W.DoWarshall();
    W.print_result();

    return 0;
}