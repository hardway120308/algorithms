#include <bits/stdc++.h>

using namespace std;

inline int lowbit(int x) { return x & -x; }
bool TopRight[16];
bool TopLeft[16];
bool col[8];
string board[8];

int dfs(int i) {
    int methods = 0;
    if (i == 8) {
        return 1;
    }

    for (int j = 0; j < 8; j++) {
        if (!TopRight[i + j] and !TopLeft[i - j + 8] and !col[j] and board[i][j] != '*') {
            // 放置
            TopRight[i + j] = true;
            TopLeft[i - j + 8] = true;
            col[j] = true;
            methods += dfs(i + 1);
            TopRight[i + j] = false;
            TopLeft[i - j + 8] = false;
            col[j] = false;
        }
    }

    return methods;
}

signed main() {
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        board[i] = s;
    }
    // i+j -> Top-Right to Bottom-Left
    // i - j + 8 -> Top-Left to Bottom-Right
    memset(TopRight, 0, sizeof(TopRight));
    memset(TopLeft, 0, sizeof(TopLeft));
    memset(col, 0, sizeof(col));
    cout << dfs(0);
}