#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int f[n + 1];
        int diff_f[n + 1];

        for (int i = 1; i <= n; i++) {
            cin >> f[i];
            if (i >= 2) {
                // diff[2] = f[1] - f[2]
                // diff_f[4] = f[4] - f[5]
                diff_f[i - 1] = f[i - 1] - f[i];
            }
        }
        int all_sum = (f[1] + f[n]) / (n - 1);
        int a[n + 1];

        for (int i = 2; i <= n - 1; i++) {
            // a[2] = diff[1] - diff[2]
            // a[n-1] = diff[n-2]- diff[n-1]
            a[i] = (diff_f[i - 1] - diff_f[i]) / 2;
        }

        // 計算a1
        a[1] = (diff_f[1] - all_sum) / -2;
        a[n] = (diff_f[n - 1] + all_sum) / 2;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
