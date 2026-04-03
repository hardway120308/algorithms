#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    char map[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // bfs
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[n][m];
    memset(visited, 0, sizeof(visited));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (not visited[i][j] and map[i][j] == '.') {
                queue<pii> waiting;
                waiting.push({i, j});
                while (not waiting.empty()) {
                    auto node = waiting.front();
                    waiting.pop();
                    visited[node.first][node.second] = true;

                    for (auto d : directions) {
                        int nx = node.first + d.first;
                        int ny = node.second + d.second;
                        if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                            if (map[nx][ny] == '.' and not visited[nx][ny]) {
                                visited[nx][ny] = true;
                                waiting.push({nx, ny});
                            }
                        }
                    }
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
}
