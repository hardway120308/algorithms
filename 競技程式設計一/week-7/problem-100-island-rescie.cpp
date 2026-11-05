#include <bits/stdc++.h>
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
using namespace std;

signed main() {
    int N, M, P;
    cin >> N >> M >> P;
    int K;
    cin >> K;
    // 表示(x1,y1)到(x2,y2)中間有wall(0)或門(1~1000)
    int gates[11][11][11][11];
    // 表示(x,y)有bitmask，如果-1則沒有key，因爲同一格可能有多個key，所以要用bitmask
    int keys[11][11];
    vector<vector<vector<int>>> min_dist(N, vector<vector<int>>(M, vector<int>(1 << (P + 1), 1e9)));

    memset(gates, -1, sizeof(gates));
    memset(keys, 0, sizeof(keys));

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2, g;
        cin >> x1 >> y1 >> x2 >> y2 >> g;
        x1--;
        y1--;
        x2--;
        y2--;
        gates[x1][y1][x2][y2] = g;
        gates[x2][y2][x1][y1] = g;
    }
    int S;
    cin >> S;
    // 因爲同一個位子可能有多個key，所以要用bitmask
    for (int i = 0; i < S; i++) {
        int u, v, q;
        cin >> u >> v >> q;
        u--;
        v--;
        keys[u][v] |= (1 << q);
    }

    // {dist, keys, x, y}
    queue<tiiii> Q;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int initial_keys = 0;

    if (keys[0][0] != -1) {
        initial_keys |= keys[0][0];
    }

    Q.push({0, initial_keys, 0, 0});
    min_dist[0][0][initial_keys] = 0;

    while (not Q.empty()) {
        auto [dist, available_keys, x, y] = Q.front();
        Q.pop();

        if (dist > min_dist[x][y][available_keys]) {
            continue;
        }

        for (auto [dx, dy] : directions) {
            int nx = dx + x;
            int ny = dy + y;
            if (0 <= nx and nx < N and 0 <= ny and ny < M) {
                // 如果是牆不能擴展
                if (gates[x][y][nx][ny] == 0) {
                    continue;
                }
                // 如果是門而且沒有對應的key，則不能擴展
                if (gates[x][y][nx][ny] > 0) {
                    int door_id = gates[x][y][nx][ny];
                    bool has_the_key = available_keys & (1 << door_id);
                    if (not has_the_key) {
                        continue;
                    }
                }

                // 到達(nx,ny)能獲得的新key bitmask
                int new_keys = available_keys;
                new_keys |= keys[nx][ny];

                if (dist + 1 < min_dist[nx][ny][new_keys]) {
                    // 更新keys
                    min_dist[nx][ny][new_keys] = dist + 1;
                    Q.push({dist + 1, new_keys, nx, ny});
                }
            }
        }
    }

    int min_d = 1e9;
    for (int k = 0; k < (1 << (P + 1)); k++) {
        min_d = min(min_d, min_dist[N - 1][M - 1][k]);
    }
    if (min_d == 1e9) {
        cout << -1;
    } else {
        cout << min_d;
    }
    return 0;
}
