#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    char c[h + 2][w + 2];
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c[i][j];
        }
    }
    bool visited[h + 2][w + 2];
    memset(visited, 0, sizeof(visited));
    int ans = 0;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            bool ok = true;
            queue<pair<int, int>> waiting;
            if (c[i][j] == '.' and !visited[i][j]) {
                visited[i][j] = true;
                waiting.push({i, j});
                // 嘗試向上下左右走，然後加入可以到達的點，再以新的點重複一次
                while (!waiting.empty()) {
                    auto point = waiting.front();
                    int x = point.first;
                    int y = point.second;
                    waiting.pop();

                    if (x <= 1 or y <= 1 or x >= h or y >= w) {
                        // 碰到邊界，不合法
                        ok = false;
                    }

                    for (int k = 0; k < 4; k++) {
                        int new_x = x + dr[k];
                        int new_y = y + dc[k];
                        if (new_x >= 1 and new_x <= h and new_y >= 1 and new_y <= w) {
                            if (c[new_x][new_y] == '.' and not visited[new_x][new_y]) {
                                visited[new_x][new_y] = true;
                                waiting.push({new_x, new_y});
                            }
                        }
                    }
                }

                // print all info
                if (ok) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
