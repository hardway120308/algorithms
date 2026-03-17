#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, s, t;
    cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (abs(x - s) <= t) {
            ans++;
        }
    }
    cout << ans << endl;
}
