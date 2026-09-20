#include <bits/stdc++.h>

using namespace std;

/// @brief  (1,1)
constexpr int START_POSITION = 1 * 9 + 1;
/// @brief  (7,1)
constexpr int END_POSITION = 7 * 9 + 1;
// UDLR
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool visited[9][9];
int ans = 0;
void dfs(string& path, int position, int steps) {
    // if reach lower-left then return
    if (position == END_POSITION) {
        if (steps == 48) {
            ans++;
            return;
        } else {
            return;
        }
    }
    if (steps == 48)
        return;

    int r = position / 9;
    int c = position % 9;

    // 剪枝，若上下都不能走，而左右能走，則會形成分割的兩個區塊，不可能一次走完
    if (visited[r + 1][c] and visited[r - 1][c] and !visited[r][c - 1] and !visited[r][c + 1]) {
        return;
    }
    if (visited[r][c - 1] and visited[r][c + 1] and !visited[r - 1][c] and !visited[r + 1][c]) {
        return;
    }

    if (path[steps] == '?') {
        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i].first;
            int nc = c + directions[i].second;
            int new_position = nr * 9 + nc;
            if (!visited[nr][nc]) {
                path[steps] = "UDLR"[i];
                visited[nr][nc] = true;
                dfs(path, new_position, steps + 1);
                path[steps] = '?';
                visited[nr][nc] = false;
            }
        }
    } else {
        // follow the order
        int i;
        switch (path[steps]) {
        case 'U':
            i = 0;
            break;
        case 'D':
            i = 1;
            break;
        case 'L':
            i = 2;
            break;
        case 'R':
            i = 3;
            break;
        default:
            break;
        }

        int nr = r + directions[i].first;
        int nc = c + directions[i].second;
        int new_position = nr * 9 + nc;
        if (!visited[nr][nc]) {
            visited[nr][nc] = true;
            dfs(path, new_position, steps + 1);
            visited[nr][nc] = false;
        }
    }
}

signed main() {
    string path;

    cin >> path;
    memset(visited, 0, sizeof(visited));
    visited[1][1] = true;
    // set border
    for (int i = 0; i < 9; i++) {
        visited[i][0] = true;
        visited[i][8] = true;
        visited[0][i] = true;
        visited[8][i] = true;
    }
    dfs(path, START_POSITION, 0);
    cout << ans << '\n';
}