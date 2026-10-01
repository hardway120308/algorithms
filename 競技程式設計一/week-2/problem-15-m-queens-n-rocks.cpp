#include <bits/stdc++.h>
#define int long long
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

void create_table() {

    for (int n = 0; n <= 11; n++) {
        for (int m = 0; m <= 11; m++) {
            if (n + m <= 11) {
                N = n;
                M = m;
                int cols = 0;
                int FULL = (1 << (N + M)) - 1;
                int diag1 = 0, diag2 = 0, diag1_q = 0, diag2_q = 0;

                cout << dfs(FULL, 0, 0, 0, cols, diag1, diag2, diag1_q, diag2_q);
            }
        }
    }
}
vector<vector<int>> read_from_table() {
    vector<vector<int>> data(15, vector<int>(15, 0));
    string raw = "1 1 2 6 24 120 720 5040 40320 362880 3628800 39916800 \n \ 
                    1 0 4 24 168 1184 9668 88488 894964 9944400 120208564  \n \
                    0 0 20 132 996 8780 92632 1049940 12951636 172429412  \n  \
                    0 8 100 432 5288 59472 780488 10611384 156363220  \n   \
                    2 50 120 2504 28860 416088 6206236 100324620    \n  \
                    10 24 992 11416 172992 2710048 48272308     \n  \
                    4 280 3464 58792 900864 17963680     \n   \
                    40 736 16048 232264 5239832     \n    \
                    92 3168 46984 1200424      \n    \
                    352 7240 215056      \n     \
                    724 29480       \n     \
                    2680   ";
    stringstream ss1(raw);

    string line;
    int i = 0;
    int j = 0;
    while (getline(ss1, line)) {
        int x;
        stringstream ss2(line);
        while (ss2 >> x) {
            data[i][j] = x;
            j++;
        }
        i++;
        j = 0;
    }
    return data;
}

signed main() {
    vector<vector<int>> data = read_from_table();

    int t;
    cin >> t;

    while (t--) {
        cin >> N >> M;
        cout << data[N][M] << '\n';
    }
}