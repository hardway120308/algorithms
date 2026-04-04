#include <bits/stdc++.h>
#include <queue>
#define int long long
#define vi vector<int>
#define graph vector<map<int, int>>
#define pii pair<int, int>
using namespace std;

const int INF = 1e14;

vi dijkistra(int n, int source, graph g) {
    vi dist(n + 1, INF);
    // PQ儲存key: 距離, val: 頂點編號
    // Min-Heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 初始化
    dist[source] = 0;
    pq.push({0, source});

    while (not pq.empty()) {
        auto [pq_dist, u] = pq.top();
        pq.pop();

        // 已經有更好的解，則貪心不選它
        if (pq_dist > dist[u])
            continue;

        // v：頂點編號, w：權重
        for (auto [v, w] : g[u]) {
            // 如果聯通
            if (w == 0 or w == INF)
                continue;
            if (dist[v] > (dist[u] + w)) {
                // 更新dist
                dist[v] = dist[u] + w;
                // {距離,頂點編號}
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
// 不能使用2d array
// 使用adj list
signed main() {
    int n, m;
    cin >> n >> m;
    graph g(n);

    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        // 會有重複的
        if (g[v1].count(v2) == 0) {
            g[v1].insert({v2, weight});
        } else {
            g[v1][v2] = min(g[v1][v2], weight);
        }
    }

    auto dist = dijkistra(n, 0, g);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
}
