#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct MaxFlow {
    int N;
    vector<vector<int>> adj;
    vector<vector<int>> cap;

    MaxFlow(int n) : N(n), adj(n), cap(n, vector<int>(n)) {}

    void addEdge(int u, int v, int c) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += c;
    }

    int bfs(int s, int t, vector<int> &parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int,int>> q;
        q.push({s, 1e9});

        while (!q.empty()) {
            auto [cur, flow] = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (parent[nxt] == -1 && cap[cur][nxt] > 0) {
                    parent[nxt] = cur;
                    int new_flow = min(flow, cap[cur][nxt]);
                    if (nxt == t) return new_flow;
                    q.push({nxt, new_flow});
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(N);
        while (1) {
            int f = bfs(s, t, parent);
            if (!f) break;
            flow += f;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                cap[prev][cur] -= f;
                cap[cur][prev] += f;
                cur = prev;
            }
        }
        return flow;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int S = 0, T = n + m + 1;
    MaxFlow mf(T + 1);

    for (int i = 1; i <= n; i++) mf.addEdge(S, i, 1);
    for (int j = 1; j <= m; j++) mf.addEdge(n + j, T, 1);

    while (k--) {
        int u, v;  // u ∈ left, v ∈ right
        cin >> u >> v;
        mf.addEdge(u, n + v, 1);
    }

    cout << mf.maxflow(S, T);
}
