#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<ll, ll>> seg(N);

    for (int i = 0; i < N; i++) {
        ll L, R;
        cin >> L >> R;
        seg[i] = {R, L}; // sort by R
    }

    sort(seg.begin(), seg.end());

    vector<ll> R(N), L(N);

    for (int i = 0; i < N; i++) {
        R[i] = seg[i].first;
        L[i] = seg[i].second;
    }

    auto feasible = [&](ll D) -> bool {
        vector<int> dp(N);
        vector<int> pref(N);

        int bestOverall = 0;

        for (int i = 0; i < N; i++) {
            ll limit = L[i] - D;

            int p = upper_bound(R.begin(), R.end(), limit) - R.begin();

            int best = (p == 0 ? 0 : pref[p - 1]);

            dp[i] = best + 1;

            pref[i] = dp[i];
            if (i)
                pref[i] = max(pref[i], pref[i - 1]);

            bestOverall = max(bestOverall, dp[i]);
        }

        return bestOverall >= K;
    };

    // 先檢查是否能選 K 個互不重疊區間
    if (!feasible(1)) {
        cout << -1 << '\n';
        return 0;
    }

    ll lo = 1, hi = 1000000000LL;
    ll ans = 1;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;

        if (feasible(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
