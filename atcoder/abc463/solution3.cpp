#include "bits/stdc++.h"
#define int long long

using namespace std;

void solve() {}

signed main() {
    int n;
    cin >> n;
    int h, l;

    // 第n分鐘後,身高
    vector<pair<int, int>> PEOPLES;

    for (int i = 0; i < n; i++) {
        cin >> h >> l;
        PEOPLES.push_back({l, h});
    }

    sort(PEOPLES.begin(), PEOPLES.end());

    int dp[n];
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            dp[i] = PEOPLES[i].second;
        } else {
            dp[i] = max(dp[i + 1], PEOPLES[i].second);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        auto it = upper_bound(PEOPLES.begin(), PEOPLES.end(), make_pair(t, 1e9 + 1));

        cout << dp[it - PEOPLES.begin()] << endl;
    }
}
