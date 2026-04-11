#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    char map[h + 2][w + 2];
    // 0 unviisted, 1,2,3,4 方向 5 visited but not having previous direction
    int visited[h + 2][w + 2][4];
    pii directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    memset(map, '#', sizeof(map));
    memset(visited, 0, sizeof(visited));

    // 起點/終點
    pii S, G;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'S')
                S = {i, j};
            if (map[i][j] == 'G')
                G = {i, j};
        }
    }

    // bfs 狀態：（當前點，前一個方向）
    queue<pair<pii, int>> q;
    // 5: 無前方向
    q.push({S, 5});

    bool ok = false;
    int GD = -1;

    while (not q.empty()) {
        pii cur = q.front().first;
        int x = cur.first;
        int y = cur.second;
        // 本格的上一格怎麽走到本格
        int prev_dir = q.front().second;

        q.pop();

        if (cur == G) {
            ok = true;
            // 這個GD表示如何從最後一格走到G
            GD = prev_dir;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            pii next = {x + directions[i].first, y + directions[i].second};

            // 如果有前一個移動
            if (prev_dir != 5) {
                // i+1 和prev_dir
                // i+1表示當前的方向
                // prev_dir 表示上一個方向，即怎麽從上一個移動到本格
                if (map[x][y] == 'o' and i + 1 != prev_dir)
                    continue;
                if (map[x][y] == 'x' and i + 1 == prev_dir)
                    continue;
            }
            if (map[next.first][next.second] != '#' and visited[next.first][next.second][i] == 0) {
                // 這個表示下一格的上一格（本格）是怎麽從下一格的上上一格（本格的上一格）移動到下一格的上一格（本格）的
                visited[next.first][next.second][i] = prev_dir;
                // 1,2,3,4表方向
                q.push({next, i + 1});
            }
        }
    }

    if (ok) {
        cout << "Yes" << endl;
        // 從G走回S
        string path;

        while (G != S) {
            path += "UDLR"[GD - 1];
            int prev_d = visited[G.first][G.second][GD - 1];
            pii next = {G.first - directions[GD - 1].first, G.second - directions[GD - 1].second};
            G = next;
            GD = prev_d;
        }

        // 反轉path
        reverse(path.begin(), path.end());
        for (char c : path)
            cout << c;
    } else {
        cout << "No" << endl;
    }
}
