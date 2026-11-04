#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;
/// 使用陣列記錄從哪裏來
signed main() {
    int n, m;
    cin >> n >> m;
    char table[n][m];
    int visited[n][m];
    pii A = {0, 0};
    pii B = {0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = -1;
            cin >> table[i][j];
            if (table[i][j] == 'A') {
                A.first = i;
                A.second = j;
            }
            if (table[i][j] == 'B') {
                B.first = i;
                B.second = j;
            }
        }
    }

    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pii> waiting;
    waiting.push(A);
    string ACTS = "DURL";

    while (!waiting.empty()) {
        auto node = waiting.front();
        int x = node.first;
        int y = node.second;
        waiting.pop();

        if (table[x][y] == 'B') {
            break;
        }

        for (int i = 0; i < directions.size(); i++) {
            auto d = directions[i];
            int ACTION = i;
            int nx = x + d.first;
            int ny = y + d.second;

            if (0 <= nx and nx < n and 0 <= ny and ny < m) {
                if (visited[nx][ny] == -1) {
                    if (table[nx][ny] == '.' or table[nx][ny] == 'B') {
                        waiting.push({nx, ny});
                        visited[nx][ny] = ACTION;
                    }
                }
            }
        }
    }

    // 從B點往回走
    if (visited[B.first][B.second] == -1) {
        cout << "NO" << endl;
    } else {
        int len = 0;
        string s = "";
        cout << "YES" << endl;

        while (B != A) {
            auto d = directions[visited[B.first][B.second]];
            int nx = B.first - d.first;
            int ny = B.second - d.second;
            s += ACTS[visited[B.first][B.second]];
            B = {nx, ny};
        }
        cout << s.length() << endl;
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}
