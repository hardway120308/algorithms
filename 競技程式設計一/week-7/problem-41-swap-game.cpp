#include <bits/stdc++.h>

using namespace std;

signed main() {
    string arr;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char x;
            cin >> x;
            arr.push_back(x);
        }
    }

    // 狀態：arr[i][j](3*3陣列)
    int ans = 0;
    // {layer, 陣列}
    queue<pair<int, string>> Q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // 使用unordered_set 替代 map（紅黑樹 -> 雜湊表）
    unordered_set<string> visited;

    Q.push({0, arr});
    while (not Q.empty()) {
        auto [layer, p] = Q.front();
        Q.pop();

        bool complete = true;

        if (p != "123456789") {
            complete = false;
        }

        if (complete) {
            ans = layer;
            break;
        }

        for (int a = 0; a < 9; a++) {
            int i = a / 3;
            int j = a % 3;
            for (auto [dx, dy] : directions) {
                int nx = i + dx;
                int ny = j + dy;
                if (0 <= nx and nx < 3 and 0 <= ny and ny < 3) {
                    // swap (nx,ny) and (i,j)
                    int nidx = nx * 3 + ny;
                    swap(p[a], p[nidx]);
                    if (visited.count(p) == 0) {
                        Q.push({layer + 1, p});
                        visited.insert(p);
                    }
                    swap(p[a], p[nidx]);
                }
            }
        }
    }
    cout << ans << endl;
}
// 用2d array會tle
signed tle_main() {
    vector<vector<int>> arr(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // 狀態：arr[i][j](3*3陣列)
    int ans = 0;
    queue<pair<int, vector<vector<int>>>> Q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    map<vector<vector<int>>, bool> visited;

    Q.push({0, arr});
    while (not Q.empty()) {
        auto [layer, p] = Q.front();
        Q.pop();

        bool complete = true;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (p[i][j] != i * 3 + j + 1) {
                    complete = false;
                    break;
                }
            }
            if (not complete) {
                break;
            }
        }

        if (complete) {
            ans = layer;
            break;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (auto [dx, dy] : directions) {
                    int nx = i + dx;
                    int ny = j + dy;
                    if (0 <= nx and nx < 3 and 0 <= ny and ny < 3) {
                        // swap (nx,ny) and (i,j)
                        auto np = p;
                        swap(np[i][j], np[nx][ny]);
                        if (not visited[np]) {
                            Q.push({layer + 1, np});
                            visited[np] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}