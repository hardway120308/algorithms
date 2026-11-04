#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
int n, m;

pii walk(vector<vector<char>>& graph, int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;
    if (0 <= nx and nx < n and 0 <= ny and ny < m and graph[nx][ny] != '#') {
        return {nx, ny};
    } else {
        return {-1, -1};
    }
}

signed main() {

    cin >> n >> m;
    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> monsters_arrived(n, vector<int>(m, 1e9));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    pii A;
    pii B = {-1, -1};
    vector<pii> monsters;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                A = {i, j};
            }
            if (graph[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    // mutli-source BFS with monsters to find the min time that monsters can reach each cell
    queue<pii> q;
    vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (auto monster : monsters) {
        q.push(monster);
        monsters_arrived[monster.first][monster.second] = 0;
    }

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
            pii next = walk(graph, cur.first, cur.second, dx, dy);
            if (next.first != -1 and monsters_arrived[next.first][next.second] == 1e9) {
                monsters_arrived[next.first][next.second] =
                    min(monsters_arrived[next.first][next.second], monsters_arrived[cur.first][cur.second] + 1);
                q.push(next);
            }
        }
    }

    // now monsters_arrived[i][j] contains the min time that monsters can reach cell (i, j)
    // check if there is a path from A to the border of the grid that is faster than monsters
    // i.e every time A moves to a cell, monsters should not have arrived at that cell yet

    q.push(A);

    int step = 0;
    while (!q.empty()) {
        // 記錄最早到達的時間，因為 BFS 是層層展開的，所以每一層都是同一個時間
        // 使用while+for
        int q_size = q.size();
        for (int _i = 0; _i < q_size; _i++) {
            pii cur = q.front();
            q.pop();

            // if A has reached the border of the grid, then we have found a path
            if (cur.first == 0 or cur.first == n - 1 or cur.second == 0 or cur.second == m - 1) {
                // back from border to A to find the path
                vector<char> path;
                while (cur != A) {
                    int dir = visited[cur.first][cur.second] - 1;
                    if (dir == 0) {
                        path.push_back('D');
                    } else if (dir == 1) {
                        path.push_back('U');
                    } else if (dir == 2) {
                        path.push_back('R');
                    } else if (dir == 3) {
                        path.push_back('L');
                    }
                    cur = walk(graph, cur.first, cur.second, -directions[dir].first, -directions[dir].second);
                }
                reverse(path.begin(), path.end());
                cout << "YES" << endl;
                cout << path.size() << endl;
                for (auto c : path) {
                    cout << c;
                }
                cout << endl;
                return 0;
            }

            for (int i = 0; i < 4; i++) {
                {
                    auto [dx, dy] = directions[i];
                    pii next = walk(graph, cur.first, cur.second, dx, dy);
                    if (next.first != -1 and visited[next.first][next.second] == 0) {
                        if (monsters_arrived[next.first][next.second] > step + 1) {
                            visited[next.first][next.second] = i + 1;
                            q.push(next);
                        }
                    }
                }
            }
        }
        step++;
    }
    cout << "NO" << endl;
}