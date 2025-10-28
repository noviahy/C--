// 백준 11657번
// Bellman-Ford
// C++

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

class Bellman {
private:
    vector<Edge> edges;
    int N;

public:
    Bellman(int n) : N(n) {}

    void addEdge(int s, int e, int w) {
        edges.push_back({s, e, w});
    }

    void DoBellman() {
        vector<long long> D(N + 1, LLONG_MAX);
        D[1] = 0;

        // N-1번 반복
        for (int i = 1; i <= N - 1; i++) {
            bool modified = false;
            for (auto &e : edges) {
                if (D[e.u] != LLONG_MAX && D[e.v] > D[e.u] + e.w) {
                    D[e.v] = D[e.u] + e.w;
                    modified = true;
                }
            }
            if (!modified) break;
        }

        // 음수 사이클 체크
        for (auto &e : edges) {
            if (D[e.u] != LLONG_MAX && D[e.v] > D[e.u] + e.w) {
                cout << -1 << endl;
                return;
            }
        }

        // 2번 도시부터 N번 도시까지 출력
        for (int i = 2; i <= N; i++) {
            if (D[i] == LLONG_MAX)
                cout << -1 << endl;
            else
                cout << D[i] << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Bellman B(n);
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        B.addEdge(s, e, w);
    }

    B.DoBellman();
    return 0;
}