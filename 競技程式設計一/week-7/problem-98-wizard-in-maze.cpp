#include <bits/stdc++.h>
#include <queue>
#define pii pair<int, int>
#define tiii tuple<int, int, int>
using namespace std;

// 使用 weighted-bfs (類似dijkstra)
// 當成本爲0時放到deque的front
// 當成本爲1時放到deque的last
// 不需要記錄visited，因爲第一次到的時候不一定是最佳解
signed main() {
    int h, w;
    pii C, W;
    cin >> h >> w;
    cin >> C.first >> C.second;
    cin >> W.first >> W.second;

    C.first--;
    C.second--;
    W.first--;
    W.second--;
    vector<vector<char>> graph(h, vector<char>(w));
    vector<vector<int>> dist(h, vector<int>(w, 1e9));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
        }
    }

    deque<pii> Q;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    dist[C.first][C.second] = 0;
    Q.push_back({C.first, C.second});

    while (not Q.empty()) {
        auto [x, y] = Q.front();
        int magic_use = dist[x][y];

        Q.pop_front();

        // action 1: go UDLR
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (0 <= nx and nx < h and 0 <= ny and ny < w and graph[nx][ny] != '#') {
                // 現在擴展的這個狀態是更好的解
                if (dist[nx][ny] > magic_use) {
                    Q.push_front({
                        nx,
                        ny,
                    });
                    dist[nx][ny] = magic_use;
                }
            }
        }

        // action 2: use magic
        for (auto dx : {-2, -1, 0, 1, 2}) {
            for (auto dy : {-2, -1, 0, 1, 2}) {
                int nx = x + dx;
                int ny = y + dy;
                if (0 <= nx and nx < h and 0 <= ny and ny < w and graph[nx][ny] != '#') {
                    if (dist[nx][ny] > magic_use + 1) {
                        Q.push_back({nx, ny});
                        dist[nx][ny] = magic_use + 1;
                    }
                }
            }
        }
    }
    if (dist[W.first][W.second] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dist[W.first][W.second];
    }
    return 0;
}

// 或者可以使用dijkstra，但有可能會TLE，時間複雜度O(E+logV)
signed dijkstra_main() {
    int h, w;
    pii C, W;
    cin >> h >> w;
    cin >> C.first >> C.second;
    cin >> W.first >> W.second;

    C.first--;
    C.second--;
    W.first--;
    W.second--;
    vector<vector<char>> graph(h, vector<char>(w));
    vector<vector<int>> dist(h, vector<int>(w, 1e9));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> graph[i][j];
        }
    }

    priority_queue<pii, vector<pii>, greater<pii>> Q;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    dist[C.first][C.second] = 0;
    Q.push({C.first, C.second});

    while (not Q.empty()) {
        int new_count = 0;
        auto [x, y] = Q.top();
        int magic_use = dist[x][y];

        Q.pop();

        // action 1: go UDLR
        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (0 <= nx and nx < h and 0 <= ny and ny < w and graph[nx][ny] != '#') {
                // 現在擴展的這個狀態是更好的解
                if (dist[nx][ny] > magic_use) {
                    Q.push({
                        nx,
                        ny,
                    });
                    dist[nx][ny] = magic_use;
                    new_count++;
                }
            }
        }

        // action 2: use magic
        for (auto dx : {-2, -1, 0, 1, 2}) {
            for (auto dy : {-2, -1, 0, 1, 2}) {
                int nx = x + dx;
                int ny = y + dy;
                if (0 <= nx and nx < h and 0 <= ny and ny < w and graph[nx][ny] != '#') {
                    if (dist[nx][ny] > magic_use + 1) {
                        Q.push({nx, ny});
                        dist[nx][ny] = magic_use + 1;
                    }
                }
            }
        }
    }
    if (dist[W.first][W.second] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dist[W.first][W.second];
    }
    return 0;
}
