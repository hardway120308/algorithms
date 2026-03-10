#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    int road[n + 1];
    int road_prefix_sum[n + 1];
    memset(road, 0, sizeof(road));
    for (int i = 0; i < m; i++) {
        int broken_location;
        cin >> broken_location;
        road[broken_location] = 1;
    }
    // 計算prefix sum

    road_prefix_sum[0] = 0;

    for (int i = 1; i < (n + 1); i++) {
        road_prefix_sum[i] = road_prefix_sum[i - 1] + road[i];
    }

    for (int i = 0; i < k; i++) {
        int left, right;
        cin >> left >> right;
        int shock_count = road_prefix_sum[right] - road_prefix_sum[left - 1];
        if (shock_count >= t) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
