#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int col[20], diag1[40], diag2[40];
int ans = 0;

void dfs(int r) {
    if (r == N) {
        ans++;
        return;
    }
    for (int c = 0; c < N; c++) {
        if (col[c] || diag1[r - c + 20] || diag2[r + c]) continue;
        col[c] = diag1[r - c + 20] = diag2[r + c] = 1;
        dfs(r + 1);
        col[c] = diag1[r - c + 20] = diag2[r + c] = 0;
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << ans;
}
