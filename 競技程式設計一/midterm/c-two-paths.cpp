#include <bits/stdc++.h>
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define int long long
#define vvi vector<vector<int>>
#define ull unsigned long long
using namespace std;

vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pii S0, S1, T0, T1;

int N, M;
int INF = 1e18;
int ans = 1e18;

vvi graph;
vvi dist1;
vvi dist2;
int id(int x, int y) { return x * M + y; }

// Reverse Dijkstra
// 回傳陣列：從(i,j)走到target的最小總成本，但不包含(i,j)的成本
vvi reverseDist(pii target) {
    vvi dist(N, vector<int>(M, INF));

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    dist[target.first][target.second] = 0;
    pq.push({0, target.first, target.second});

    while (!pq.empty()) {
        auto [d, x, y] = pq.top();
        pq.pop();

        if (d != dist[x][y])
            continue;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            int nd = d + graph[x][y];

            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                pq.push({nd, nx, ny});
            }
        }
    }

    return dist;
}

// 對B做Dijkstra找到B的最短路徑在不能走spare的狀況下
int shortestPath(pii start, pii target, ull spare) {
    if (spare & (1ULL << id(start.first, start.second)))
        return INF;

    vvi dist(N, vector<int>(M, INF));
    priority_queue<tiii, vector<tiii>, greater<tiii>> PQ;

    dist[start.first][start.second] = graph[start.first][start.second];
    PQ.push({dist[start.first][start.second], start.first, start.second});

    while (not PQ.empty()) {
        auto [d, x, y] = PQ.top();
        PQ.pop();

        if (d > dist[x][y])
            continue;

        // 到達target
        if (make_pair(x, y) == target)
            return d;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            ull bit = 1ULL << id(nx, ny);
            if (spare & bit)
                continue;

            int nd = d + graph[nx][ny];
            if (nd < dist[nx][ny]) {
                dist[nx][ny] = nd;
                PQ.push({nd, nx, ny});
            }
        }
    }

    return INF;
}

// 對A進行DFS找到走向T0的最小成本路徑
void dfsA(pii pos, ull spare, int cost) {
    // (S0走到pos成本 + pos走到T0的最小成本 + S1的成本 + B從S1到T1的最小成本) 若大於 and則非最優解
    if (cost + dist1[pos.first][pos.second] + graph[S1.first][S1.second] + dist2[S1.first][S1.second] >= ans)
        return;

    // 到達T0
    if (pos == T0) {
        // B在這條路徑上到T1的成本
        int other = shortestPath(S1, T1, spare);

        if (other != INF)
            ans = min(ans, cost + other);

        return;
    }

    for (auto [dx, dy] : directions) {
        int nx = pos.first + dx;
        int ny = pos.second + dy;

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        pii nxt = {nx, ny};

        ull bit = 1ULL << id(nx, ny);

        if (spare & bit)
            continue;

        // A 不能走到B的起點、終點
        if (nxt == S1 || nxt == T1)
            continue;

        dfsA(nxt, spare | bit, cost + graph[nx][ny]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    graph.assign(N, vector<int>(M));
    dist1.assign(N, vector<int>(M));
    dist2.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    cin >> S0.first >> S0.second >> T0.first >> T0.second;
    cin >> S1.first >> S1.second >> T1.first >> T1.second;

    S0.first--;
    S0.second--;
    T0.first--;
    T0.second--;
    S1.first--;
    S1.second--;
    T1.first--;
    T1.second--;

    ull spare = 1ULL << id(S0.first, S0.second);
    dist1 = reverseDist(T0);
    dist2 = reverseDist(T1);
    dfsA(S0, spare, graph[S0.first][S0.second]);

    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
