#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

double dfs(double memory[10001][100], vector<int> c, vector<int> p, int i, int s) {
    if (s == 0) {
        return 0;
    }
    if (i == 0) {
        return 0;
    }
    double s_real = (double)s / 100;
    double sub_s = s_real * (1 - (double)p[i - 1] / 100);
    int sub_s_for_index = sub_s * 100;
    if (memory[i][s] != 0) {
        return memory[i][s];
    } else {
        memory[i][s] = max(dfs(memory, c, p, i - 1, s), dfs(memory, c, p, i - 1, sub_s_for_index) + c[i - 1] * s_real);
        return memory[i][s];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int s = 1000;

        vector<int> c;
        vector<int> p;
        // 狀態：在前i項，體力s下可以得到的分數
        double dp[n + 1][s + 1];

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            c.push_back(x);
            p.push_back(y);
        }
        reverse(c.begin(), c.end());
        reverse(p.begin(), p.end());
        double v[10001][100];
        memset(v, 0, sizeof(v));
        cout << setprecision(16) << dfs(v, c, p, n, 100) << endl;
    }
}
