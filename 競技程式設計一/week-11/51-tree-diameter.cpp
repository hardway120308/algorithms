#include <bits/stdc++.h>

using namespace std;

int D = -1;
int point = 0;
void dfs(vector<vector<int>>& tree, int node, int parent = -1, int dist = 0) {
    for (auto v : tree[node]) {
        if (v != parent) {
            dfs(tree, v, node, dist + 1);
        }
    }
    if (dist > D) {
        point = node;
        D = dist;
    }
}

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> tree(N + 1, vector<int>(0));
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[b].emplace_back(a);
        tree[a].emplace_back(b);
    }
    int a = 1;
    dfs(tree, a);
    D = -1;
    dfs(tree, point);
    cout << D << '\n';

    return 0;
}
