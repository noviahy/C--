#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // N: 정점 수, M: 간선 수

    const long long INF = 1e15;
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));

    // 자기 자신까지 거리 0
    for (int i = 1; i <= N; i++) dist[i][i] = 0;

    // 간선 입력
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], (long long)w); // 여러 간선 중 최소
    }

    // Floyd-Warshall
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}