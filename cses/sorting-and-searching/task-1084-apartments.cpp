#include <algorithm>
#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    // a 申請者
    // b 公寓
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);
    int ap = 0, bp = 0, ans = 0;
    while (ap < n && bp < m) {
        if (abs(a[ap] - b[bp]) <= k) { // 剛好符合
            ap++;
            bp++;
            ans++;
        } else if (b[bp] > a[ap] + k) { // 公寓太大，找下一個申請者
            ap++;
        } else if (b[bp] < a[ap] - k) { // 公寓太小，找下一個公寓
            bp++;
        }
    }
    cout << ans << endl;
}
