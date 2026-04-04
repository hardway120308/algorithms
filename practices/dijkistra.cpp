#include <bits/stdc++.h>
#include <queue>
#define int long long
#define vi vector<int>
#define arr2d vector<vector<int>>
#define pii pair<int, int>
using namespace std;
const int INF = 1e10;
vi dijkistra(int n, int source, arr2d g) {
    vi dist(n + 1, INF);
    // PQ儲存key: 距離, val: 頂點編號
    // Min-Heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 初始化
    dist[source] = 0;
    pq.push({0, source});

    while (not pq.empty()) {
        pii u = pq.top();
        pq.pop();

        if (u.first > dist[u.second])
            continue;

        for (int v = 0; v < n; v++) {
            // 如果聯通
            int w = g[u.second][v];
            if (w == 0 or w == INF)
                continue;
            if (dist[v] > (dist[u.second] + w)) {
                // 更新dist
                dist[v] = dist[u.second] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
signed main() {
    int n, m;
    cin >> n >> m;
    arr2d g(n, vector<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        g[v1][v2] = weight;
    }

    auto dist = dijkistra(n, 0, g);

    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
}
