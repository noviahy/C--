// 백준 6086번
// 최대 유량
// C++

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Flow
{
private:
    vector<vector<int>> adj;
    vector<vector<int>> capacity;

    int N;
    int start;
    int end;

public:
    Flow(int N) : N(N)
    {
        adj.resize(52);
        capacity.resize(N, vector<int>(52, 0));
        start = ChangeAlp('A');
        end = ChangeAlp('Z');
    }

    int ChangeAlp(char Alp) // 알파벳을 정수로 바꿈 A == 0
    {
        if ('A' <= Alp && Alp <= 'Z')
            return Alp - 'A';
        if ('a' <= Alp && Alp <= 'z')
            return Alp - 'a' + 26;
        return -1; // 예외 처리
    }

    void InputEdge(char P, char C, int w)
    {
        int p = ChangeAlp(P);
        int c = ChangeAlp(C);

        if (P == -1 || C == -1) return;

        adj[p].push_back(c);
        adj[c].push_back(p);
        capacity[p][c] += w;
    }

    bool DoBFS(vector<int> &parent)
    {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(start);
        parent[start] = -2; // 시작점 표시

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (parent[v] == -1 && capacity[u][v] > 0)
                {
                    parent[v] = u;
                    if (v == end)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int max_flow()
    {
        int total_flow = 0;
        vector<int> parent(52);

        while (DoBFS(parent))
        {
            int bottle_neck = 1e9;
            int v = end;
            while (v != start)
            {
                int u = parent[v];
                bottle_neck = min(bottle_neck, capacity[u][v]);
                v = u;
            }

            v = end;

            while (v != start)
            {
                int u = parent[v];

                capacity[u][v] -= bottle_neck;
                capacity[v][u] += bottle_neck;
                v = u;
            }

            total_flow += bottle_neck;
        }
        return total_flow;
    }
};

int main()
{
    int N;
    cin >> N;

    Flow flow(52);
    for (int i = 0; i < N; i++)
    {
        char p, c;
        int w;

        cin >> p >> c >> w;
        flow.InputEdge(p, c, w);
    }

    cout << flow.max_flow();

    return 0;
}