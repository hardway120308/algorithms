#include <bits/stdc++.h>
#include <queue>
#define tiii tuple<int, int, int>
#define pii pair<int, int>
using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    pii START = {-1, -1};
    vector<vector<int>> graph(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                START = {i, j};
            }
        }
    }

    priority_queue<tiii, vector<tiii>, greater<tiii>> Q;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    Q.push({0, START.first, START.second});
    visited[START.first][START.second] = true;
    int ans = 1e9;

    while (not Q.empty()) {
        auto [distance, x, y] = Q.top();
        Q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx and nx < h and 0 <= ny and ny < w and graph[nx][ny] != 2 and not visited[nx][ny]) {
                visited[nx][ny] = true;
                if (graph[nx][ny] == 1) {
                    if (graph[x][y] == 0) {
                        ans = min(ans, distance);
                    } else {
                        Q.push({distance, nx, ny});
                    }
                } else {
                    Q.push({distance + 1, nx, ny});
                }
            }
        }
    }

    if (ans == 1e9) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}
