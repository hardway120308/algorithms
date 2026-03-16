#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    // 資料（location, event_type）
    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }

    sort(events.begin(), events.end());

    int ans = 0;
    int value = 0;
    int range_start = -1;
    int range_end = -1;

    for (auto event : events) {
        value += event.second;
        if (value >= k and range_start == -1) {
            range_start = event.first;
        }
        if (value < k and range_start != -1) {
            range_end = event.first;
            ans += range_end - range_start;
            range_start = -1;
            range_end = -1;
        }
    }

    cout << ans << endl;

    return 0;
}
