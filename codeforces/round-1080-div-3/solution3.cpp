#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a)
            cin >> x;

        // adjacency list
        // 條件 a != b且 a+b !=7
        vector<vector<int>> adj(7);
        for (int x = 1; x <= 6; x++) {
            for (int y = 1; y <= 6; y++) {
                if (y != x && y != 7 - x) {
                    adj[x].push_back(y);
                }
            }
        }

        // dp[i][x]: 前i個項目中（0-indexed）使最後一個數字是x的最小方法數
        vector<vector<int>> dp(n, vector<int>(7, 1e9));

        // init，dp[0][1~6]在a[0]爲這個值時爲0，其他都必須改一次
        for (int x = 1; x <= 6; x++) {
            dp[0][x] = (x == a[0] ? 0 : 1);
        }

        // 轉移
        for (int i = 1; i < n; i++) {
            // 窮舉：把a[i]改成x
            for (int x = 1; x <= 6; x++) {
                // 窮舉y爲前一個數字可能的選擇
                for (int y : adj[x]) {
                    // dp[i][x]的最小方法數爲，
                    // 窮舉所有的a[i-1]是可以滿足條件（adj list）+ 把a[i]改成x的成本(如果x==a[i]則0)
                    dp[i][x] = min(dp[i][x], dp[i - 1][y] + (x != a[i]));
                }
            }
        }

        int ans = 1e9;
        for (int x = 1; x <= 6; x++) {
            ans = min(ans, dp[n - 1][x]);
        }

        cout << ans << '\n';
    }
}
