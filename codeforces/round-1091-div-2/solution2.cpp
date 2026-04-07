#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        bool a[n];
        int SP[k];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < k; i++)
            cin >> SP[i];

        SP[0]--;
        bool TARGET = a[SP[0]];

        int need_count = 0;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            if (a[l] == TARGET and (l + 1) <= SP[0]) {
                l++;
            } else if (a[r] == TARGET and SP[0] <= (r - 1)) {
                r--;
            } else {
                // 執行reverse
                if (l == r and a[l] == TARGET) {
                    break;
                }
                // 設定從l到r反轉
                TARGET = not TARGET;
                // 如果完全一致就break
                need_count++;
            }
        }
        cout << need_count << endl;
    }
}
