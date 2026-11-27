#include <bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define int long long
using namespace std;
int N;

// 此節點的子樹大小（包含自己）
vi sz;
// 這個節點到所有其他節點的距離和
vi ans;
// 此節點的子樹的所有點到這個節點的距離和，leave node爲0
vi down;

// 求到node的子樹的所有點的的距離和
// 對於u->v，v內所有點到v的距離和爲d,則v子樹內所有點到到u的距離和爲d+size[v]*1（因爲每個點都要再走過v->u）
void dfs1(vvi& tree, int node, int parent = -1) {
    // 定義leave node的down爲0
    down[node] = 0;
    sz[node] = 1;
    for (auto children : tree[node]) {
        if (children != parent) {
            // 因爲需要sz[children]的資料，所以要先dfs
            dfs1(tree, children, node);
            sz[node] += sz[children];
            down[node] += down[children] + sz[children];
        }
    }
}

// 計算ans，換根公式：
// 令node->children，已知ans[node]（所有點到node的距離總和）
// 現在移動根從node到children，則ans[node]會先減少1*sz[children]（在children子樹內的所有點距離都減1）
// 再增加N-sz[children]*1（共有N-sz[v]個節點在children之外）
// ans[children] = ans[node] + N - 2sz[children]
void dfs2(vvi& tree, int node, int parent = -1) {
    // 初始狀態，根節點的答案就是根節點子樹所有點到此的距離和
    if (node == 1) {
        ans[1] = down[1];
    }
    for (auto children : tree[node]) {
        // 換根
        if (children != parent) {
            // 所有其他點到children的距離和ans[children] = ans[node] + N - 2sz[children]
            ans[children] = ans[node] + N - 2 * sz[children];
            // dfs需要children的資料，所以要先動態規劃狀態轉移
            dfs2(tree, children, node);
        }
    }
}

// 計算sum of the node to all the other node
// 分成up和down，利用換根求出
signed main() {
    cin >> N;
    vvi tree(N + 1, vector<int>(0));
    sz.assign(N + 1, 0);
    ans.assign(N + 1, 0);
    down.assign(N + 1, 0);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    dfs1(tree, 1);
    dfs2(tree, 1);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
