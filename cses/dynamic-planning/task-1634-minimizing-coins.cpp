#include <bits/stdc++.h>
#define int long long
using namespace std;

// 簡單的寫法會MLE
// 要做空間優化
signed main() {
    int n, x;
    cin >> n >> x;
    int amt[n];
    for (int i = 0; i < n; i++)
        cin >> amt[i];

    sort(amt, amt + n);
    int dp[x + 1];

    for (int i = 0; i < x + 1; i++)
        dp[i] = 1e9;
    dp[0] = 0;

    // 硬幣
    for (int i = 1; i < n + 1; i++) {
        // 目標金額
        for (int j = 1; j < x + 1; j++) {
            int now_amt = amt[i - 1];
            if (now_amt <= j) {
                dp[j] = min(dp[j], dp[j - amt[i - 1]] + 1);
            } else {
                dp[j] = dp[j];
            }
        }
    }
    if (dp[x] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }
}
