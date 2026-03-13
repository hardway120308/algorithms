#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w, n;
    int ans = 0;
    cin >> h >> w >> n;
    int warehouse[h][w];

    memset(warehouse, 0, sizeof(warehouse));

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '#') {
                warehouse[i][j] = 1;
                ans++;
            }
        }
    }
    string t;
    int now_x = 0;
    int now_y = 0;
    cin >> t;
    if (warehouse[now_y][now_x] == 1) {
        warehouse[now_y][now_x]--;
        ans -= 1;
    }
    for (int i = 0; i < t.length(); i++) {
        char action = t[i];
        if (action == 'U') {
            if (now_y >= 1) {
                now_y--;
            }
        }

        if (action == 'D') {
            if (now_y <= h - 2) {
                now_y++;
            }
        }
        if (action == 'L') {
            if (now_x >= 1) {
                now_x--;
            }
        }
        if (action == 'R') {
            if (now_x <= w - 2) {
                now_x++;
            }
        }
        if (warehouse[now_y][now_x] == 1) {
            warehouse[now_y][now_x]--;
            ans -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}
