#include <bits/stdc++.h>
#include <queue>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define pii pair<int, int>
using namespace std;

// 不能同時進行Dijkstra對坡度和距離，必須先
// 1. Dijkstra最小化到右下角的坡度
// 2. 以這個坡度走BFS到右下角找最短距離
signed main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    // best 坡度, 距離
    vector<vector<int>> min_slope(n, vector<int>(n, 1e9));
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> Q;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // Minimizes slopes
    // 使用dijkstra
    Q.push({0, 0, 0});
    min_slope[0][0] = 0;

    while (not Q.empty()) {
        auto [slope_to_there, x, y] = Q.top();
        Q.pop();

        if (slope_to_there > min_slope[x][y]) {
            continue;
        }

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx and nx < n and 0 <= ny and ny < n) {
                int slope_to_new_point = abs(graph[nx][ny] - graph[x][y]);
                int new_slope = max(slope_to_there, slope_to_new_point);
                if (new_slope < min_slope[nx][ny]) {
                    min_slope[nx][ny] = new_slope;
                    Q.push({new_slope, nx, ny});
                }
            }
        }
    }

    // bfs 走到右下角
    queue<pii> bfs_q;
    bfs_q.push({0, 0});
    visited[0][0] = true;
    int steps = 0;
    while (not bfs_q.empty()) {
        int q_size = bfs_q.size();
        for (int _i = 0; _i < q_size; _i++) {
            auto [x, y] = bfs_q.front();
            bfs_q.pop();

            if (x == n - 1 and y == n - 1) {
                cout << min_slope[n - 1][n - 1] << endl;
                cout << steps << endl;
                return 0;
            }

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (0 <= nx and nx < n and 0 <= ny and ny < n and
                    abs(graph[nx][ny] - graph[x][y]) <= min_slope[n - 1][n - 1] and not visited[nx][ny]) {
                    visited[nx][ny] = true;
                    bfs_q.push({nx, ny});
                }
            }
        }
        steps++;
    }

    return 0;
}
