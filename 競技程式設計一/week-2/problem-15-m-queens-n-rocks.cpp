#include <bits/stdc++.h>

using namespace std;
int N, M;

inline int lowbit(int x) { return x & -x; }

int dfs(int FULL, int row, int n, int m, int cols, int diag1, int diag2, int diag1_q, int diag2_q) {
    int ans = 0;
    if (row == (N + M)) {
        if (n == N and m == M) {
            // cout << "reached\n";
            return 1;
        } else {
            return 0;
        }
    }

    int queen_available = FULL & (~cols & ~diag1 & ~diag2 & ~diag1_q & ~diag2_q);
    int rocks_available = FULL & (~cols & ~diag1 & ~diag2);
    if (n < N) {
        while (queen_available) {
            int lb = lowbit(queen_available);
            int num = __builtin_ctz(lb);
            int p = (1 << num);

            // cout << "place queen at" << row << ' ' << num << '\n';
            // 需要把diag正常傳遞出去，就算沒有新的棋子違反也需要
            ans +=
                dfs(FULL, row + 1, n + 1, m, cols | p, (diag1 | p) << 1, (diag2 | p) >> 1, diag1_q << 1, diag2_q >> 1);

            queen_available -= lb;
        }
    }
    if (m < M) {
        while (rocks_available) {
            int lb = lowbit(rocks_available);
            int num = __builtin_ctz(lb);
            int p = (1 << num);

            // cout << "place rock at" << row << ' ' << num << '\n';
            // 需要把diag正常傳遞出去，就算沒有新的棋子違反也需要
            ans +=
                dfs(FULL, row + 1, n, m + 1, cols | p, diag1 << 1, diag2 >> 1, (diag1_q | p) << 1, (diag2_q | p) >> 1);

            rocks_available -= lb;
        }
    }

    return ans;
}

signed main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> N >> M;
        int cols = 0;
        int FULL = (1 << (N + M)) - 1;
        int diag1 = 0, diag2 = 0, diag1_q = 0, diag2_q = 0;

        cout << dfs(FULL, 0, 0, 0, cols, diag1, diag2, diag1_q, diag2_q) << '\n';
    }
}