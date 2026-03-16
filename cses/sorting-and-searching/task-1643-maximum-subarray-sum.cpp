#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    int x[n];
    int dp[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    dp[0] = x[0];

    for (int i = 1; i < n; i++) {
        // 選擇：建立新array，或者加入前一個array中選擇最優解
        dp[i] = max(dp[i - 1] + x[i], x[i]);
    }

    cout << *max_element(dp, dp + n) << endl;

    return 0;
}
