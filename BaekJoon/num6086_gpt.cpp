#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int NODE_CNT = 52;
int capacity[NODE_CNT][NODE_CNT];
int flow_through[NODE_CNT][NODE_CNT];
vector<int> adj[NODE_CNT];

int nodeIndex(char c) 
{
    if ('A' <= c && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int P;
    cin >> P;

    while (P--) 
    {
        char cu, cv;
        int c;
        cin >> cu >> cv >> c;
        int u = nodeIndex(cu);
        int v = nodeIndex(cv);
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += c;
        capacity[v][u] += c;
    }

    int source = nodeIndex('A');
    int sink = nodeIndex('Z');
    int maxFlow = 0;

    while (true) 
    {
        vector<int> parent(NODE_CNT, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) 
        {
            int here = q.front();
            q.pop();

            for (int there : adj[here]) 
            {
                if (parent[there] == -1 && capacity[here][there] - flow_through[here][there] > 0) 
                {
                    parent[there] = here;
                    q.push(there);
                    if (there == sink) break;
                }
            }
        }

        if (parent[sink] == -1) break;

        int amount = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) 
        {
            int u = parent[v];
            amount = min(amount, capacity[u][v] - flow_through[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) 
        {
            int u = parent[v];
            flow_through[u][v] += amount;
            flow_through[v][u] -= amount;
        }
        maxFlow += amount;
    }

    cout << maxFlow << "\n";
    return 0;
}
