#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n];
}
