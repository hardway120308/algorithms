#include <bits/stdc++.h>

using namespace std;

// 第0位 不能用
constexpr int FULL = (1 << 10) - 2;
bool found = false;

inline int lowbit(int x) { return x & -x; }

void dfs(int n, string& S, vector<int>& row, vector<int>& col, vector<vector<int>>& graph) {
    // 填入80位之後會需要到81才結束
    if (n == 81) {
        cout << S << '\n';
        found = true;
        return;
    }
    if (S[n] == '.') {
        int r = n / 9;
        int c = n % 9;
        int g_r = r / 3;
        int g_c = c / 3;

        int available = FULL & (~row[r] & ~col[c] & ~graph[g_r][g_c]);

        while (available) {
            int num = __builtin_ctz(lowbit(available));
            available -= lowbit(available);

            S[n] = '0' + num;
            row[r] |= (1 << num);
            col[c] |= (1 << num);
            graph[g_r][g_c] |= (1 << num);

            dfs(n + 1, S, row, col, graph);

            row[r] ^= (1 << num);
            col[c] ^= (1 << num);
            graph[g_r][g_c] ^= (1 << num);
            S[n] = '.';
        }
    } else {
        dfs(n + 1, S, row, col, graph);
    }
}

signed main() {
    string S;
    while (cin >> S) {
        if (S == "end")
            break;
        found = false;
        // row不可以的數字
        vector<int> row(9, 0);
        // col不可以的數字
        vector<int> col(9, 0);
        // graph不可以的數字
        vector<vector<int>> graph(3, vector<int>(3, 0));
        // 檢查不符合的輸入
        bool invalid_input = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int position = i * 9 + j;
                if (S[position] != '.') {
                    int x = S[position] - '0';
                    int g_i = i / 3;
                    int g_j = j / 3;
                    if ((row[i] & (1 << x)) || (col[j] & (1 << x)) || (graph[g_i][g_j] & (1 << x))) {
                        invalid_input = true;
                    }
                    row[i] |= (1 << x);
                    col[j] |= (1 << x);

                    graph[g_i][g_j] |= (1 << x);
                }
            }
        }

        if (!invalid_input) {
            dfs(0, S, row, col, graph);
            if (!found) {
                cout << "No solution.\n";
            }
        } else {
            cout << "No solution.\n";
        }
    }
    return 0;
}