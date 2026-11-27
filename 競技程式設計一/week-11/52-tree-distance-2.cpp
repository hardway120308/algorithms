#include <bits/stdc++.h>

using namespace std;
// Memorizing Search不能通過，要使用換根法
// 分別計算up,down，
// down定義爲往你的子樹走的最大距離
// down是以這個節點爲根的子樹的最大長度（向下走）
// up定義爲往父節點方向走的最大距離
// up是當u->v時，我們改成以v爲根，則向上走的最大距離可能是：
// 1. 1 + u往父節點走的最大距離
// 2. 1 + v經由u往u的子節點（不包含v）走的最大距離
// 比較二者即可
vector<int> down;
vector<int> up;
int dfs1(vector<vector<int>>& tree, int node, int parent = -1) {
    int D = 0;
    for (auto v : tree[node]) {
        if (v != parent) {
            D = max(D, 1 + dfs1(tree, v, node));
        }
    }
    down[node] = D;
    return D;
}

void dfs2(vector<vector<int>>& tree, int node, int parent = -1) {
    // 計算node的down是往哪個子樹走的，因爲下一步不能包含自己，所以要存第一大和第二大
    int best_child = -1;
    int max_D = -1;
    int max_D_2 = -2;
    // 先計算node的各個子節點中，第一和第二長的distance在哪個子節點
    for (auto v : tree[node]) {
        if (v != parent) {
            int d = down[v] + 1;
            if (d > max_D) {
                best_child = v;
                swap(max_D, max_D_2);
                max_D = d;
            } else if (d > max_D_2) {
                max_D_2 = d;
            }
        }
    }
    // 向node的子節點走
    // v往上走的max距離 = max(以node開始)
    for (auto v : tree[node]) {
        if (v != parent) {
            // 必須取第二名
            if (best_child == v) {
                up[v] = 1 + max(up[node], max_D_2);
            } else {
                up[v] = 1 + max(up[node], max_D);
            }
            dfs2(tree, v, node);
        }
    }
}

signed main() {
    int N;
    cin >> N;
    vector<vector<int>> tree(N + 1, vector<int>(0));
    down.assign(N + 1, 0);
    up.assign(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    dfs1(tree, 1, -1);
    dfs2(tree, 1, -1);

    for (int i = 1; i <= N; i++) {
        cout << max(up[i], down[i]) << ' ';
    }
    cout << '\n';

    return 0;
}
