#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    // 所需技能,得到的錢
    vector<pair<int, int>> days;
    for (int i = 0; i < n; i++) {
        int hard_skills, sell;
        cin >> hard_skills >> sell;
        days.push_back({sell, hard_skills});
    }
    // 工人的skill，當前的sell
    vector<pair<int, int>> workers;

    for (int i = 0; i < m; i++) {
        int skill;
        cin >> skill;
        workers.push_back({skill, 0});
    }

    sort(workers.begin(), workers.end());

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // 只有i >= workers合法
    for (int i = 1; i <= n; i++) {
        // 找最接近工作skill，且營收最小者
        auto it = lower_bound(workers.begin(), workers.end(), std::make_pair(days[i - 1].second, (long long)-1));
        if (it != workers.end()) {
            if (it->second != 0) {
                int updated = dp[i - 1] - it->second + days[i - 1].first;

                if (dp[i - 1] < updated) {
                    dp[i] = updated;
                    it->second = days[i - 1].first;
                } else {
                    dp[i] = dp[i - 1];
                }
            } else {
                int updated = dp[i - 1] + days[i - 1].first;
                if (dp[i - 1] < updated) {
                    dp[i] = updated;
                    it->second = days[i - 1].first;
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        } else {
            dp[i] = dp[i - 1];
        }
        sort(workers.begin(), workers.end());
    }

    if (workers[0].second == 0) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
    }

    return 0;
}
