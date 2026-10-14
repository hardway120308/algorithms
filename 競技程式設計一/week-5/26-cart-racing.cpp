#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int vn, vb, c, r;
    cin >> vn >> vb >> c >> r;

    int g0, L, T;
    cin >> g0 >> L >> T;

    vector<int> best(T + 1, -1e9);
    best[0] = 0;

    // b = 加速秒數
    for (int b = 1; b <= T; b++) {
        // 需要的油
        int need = b * c - g0;
        int refill = 0;

        // 如果需要比g0更多的油
        if (need > 0) {
            refill = (need + r - 1) / r;
        }

        int time = b + refill;

        if (time > T)
            continue;

        // 距離(比普通行駛多出來的)
        int gain = b * (vb - vn) - refill * vn;
        best[time] = max(best[time], gain);
    }

    for (int t = 1; t <= T; t++) {
        best[t] = max(best[t - 1], best[t]);
    }

    // 找最早抵達時間
    for (int t = 0; t <= T; t++) {
        int dist = t * vn + best[t];

        if (dist >= L) {
            cout << "Yes\n" << t << '\n';
            return 0;
        }
    }

    cout << "No\n" << T * vn + best[T] << '\n';

    return 0;
}