#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c, k;
        cin >> n >> c >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            if (a[i] <= c) {
                // 嘗試使用k
                int used_k = min(k, c - a[i]);
                k -= used_k;
                a[i] = a[i] + used_k;
                c += a[i];
            } else {
                break;
            }
        }
        cout << c << endl;
    }
}
