#include <bits/stdc++.h>
#define int long long
using namespace std;

// 求湊到x元的排列數
signed main() {
    int n, x;
    cin >> n >> x;
    int amt[n];
    for (int i = 0; i < n; i++)
        cin >> amt[i];

    sort(amt, amt + n);
    int dp[x + 1];

    for (int i = 0; i < x + 1; i++)
        dp[i] = 0;
    // 湊到0元的方法數爲1
    dp[0] = 1;

    // 目標金額
    for (int i = 1; i <= x; i++) {
        // 金幣
        for (int j = 1; j <= n; j++) {
            int now_amt = amt[j - 1];
            if (now_amt <= i) {
                // 湊到i元的方法數 = 原本湊到i元的方法數+湊到i-amt元的方法數
                dp[i] = (dp[i] + dp[i - now_amt]) % (int)(1e9 + 7);
            } else {
                dp[i] = dp[i];
            }
        }
    }
    cout << dp[x] << endl;
}
