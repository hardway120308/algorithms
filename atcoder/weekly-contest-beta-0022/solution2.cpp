#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, m, t;
    int ans = 0;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        if (score - t >= 0) {
            // 不用補課
            continue;
        } else {
            // 嘗試補課
            int diff = t - score;
            if (m - diff >= 0) {
                // 補課成功
                m -= diff;
                ans += diff;
            } else {
                ans = -1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
