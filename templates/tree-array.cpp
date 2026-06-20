#include <bits/stdc++.h>

using namespace std;

bool visisted[50000];

// 運用到類似backtrack的思想
void dfs(vector<vector<int>> adj_list, int node) {
    visisted[node] = true;
    cout << node << ' ';
    for (auto child : adj_list[node]) {
        if (not visisted[child]) {
            // 走到底
            dfs(adj_list, child);
            // 回撤：走回來
            cout << node << ' ';
        }
    }
}

signed main() {
    memset(visisted, 0, sizeof(visisted));
    int n;
    cin >> n;
    vector<vector<int>> adj_list(50000, vector<int>(0));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }
    dfs(adj_list, 0);
}
