// BFS
// C++

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class BFS
{
private:
    vector<vector<int>> adj;
    int start, N, M;

public:
    BFS(int n, int s, int m)
        : N(n), start(s), M(m)
    {
        adj.resize(N + 1);
    }

    void addEdge(int s, int e)
    {
        adj[s].push_back(e);
        adj[e].push_back(s); // 무방향
    }

    void DoBFS()
    {
        vector<int> p(N + 1);
        vector<int> d(N + 1);
        vector<bool> visited(N + 1, false);
        queue<int> q;

        d[start] = 0;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int n : adj[u])
            {
                if (!visited[n])
                {
                    visited[n] = true;
                    d[n] = d[u] + 1;
                    p[n] = u;
                    q.push(n);
                }
            }
        }

        get_path(p);
    }

    void get_path(vector<int> p)
    {
        for (int i = 1; i <= N; i++)
        {
            vector<int> path;
            int current = i;
            while (current != start)
            {
                path.push_back(current);
                current = p[current];
            }
            path.push_back(start);

            reverse(path.begin(), path.end());

            for (int v : path)
                cout << v << " ";
            cout << endl;
        }
    }
};

int main()
{
    int start, N, M;
    cin >> N >> M >> start;

    BFS B(N, start, M);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        B.addEdge(s, e);
    }
    
    cout<<endl;

    B.DoBFS();
    return 0;
}

// sort(adj[u].begin(), adj[u].end());