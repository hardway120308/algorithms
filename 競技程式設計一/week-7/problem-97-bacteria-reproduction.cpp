#include <bits/stdc++.h>
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define int long long
using namespace std;

signed main() {
    int M, N, K, T;
    cin >> M >> N >> K >> T;
    vector<vector<int>> graph(M, vector<int>(N, 0));
    // virus, x, y, time
    vector<tiiii> bacteria;
    queue<tiiii> q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != -1 and graph[i][j] != 0) {
                bacteria.push_back({graph[i][j], i, j, 0});
            }
        }
    }

    // 排序過細菌，編號小的細菌先擴散，這樣就可以保證 BFS 的時候，同一時間的總是由細菌編號小的先到達
    sort(bacteria.begin(), bacteria.end());

    for (auto b : bacteria) {
        q.push(b);
    }

    // multi-source BFS with bacteria to spread
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        auto [i, x, y, t] = q.front();
        if (t == T) {
            break;
        }
        q.pop();

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx and nx < M and 0 <= ny and ny < N and graph[nx][ny] != -1 and graph[nx][ny] == 0) {
                graph[nx][ny] = i;
                q.push({graph[nx][ny], nx, ny, t + 1});
            }
        }
    }

    // stat all bacteria count
    vector<int> count(K + 1, 0);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != -1 and graph[i][j] != 0) {
                count[graph[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= K; i++) {
        cout << count[i] << " ";
    }

    return 0;
}