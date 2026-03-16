#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    int n, t, e;
    cin >> n >> t >> e;
    int p[n];
    int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);

    for (int i = 0; i < n; i++) {
        if (p[i] * t <= e) {
            ans++;
            e -= p[i] * t;
        }
    }

    cout << ans << endl;

    return 0;
}
