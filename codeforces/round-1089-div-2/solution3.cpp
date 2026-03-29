#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    if (!(cin >> n))
        return;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<ll> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    if (n < 2) {
        cout << "0\n";
        return;
    }

    // d[i] = gcd(a[i], a[i+1])
    vector<ll> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = std::gcd(a[i], a[i + 1]);
    }

    // L[i] is the LCM of the GCDs that index i belongs to
    vector<ll> L(n);
    L[0] = d[0];
    L[n - 1] = d[n - 2];
    for (int i = 1; i < n - 1; ++i) {
        L[i] = std::lcm(d[i - 1], d[i]);
    }

    // Check if index i can potentially be changed
    vector<bool> can_change(n, false);
    for (int i = 0; i < n; ++i) {
        if (L[i] < a[i])
            can_change[i] = true;
    }

    // Check for conflicts between adjacent changes
    vector<bool> conflict(n - 1, false);
    for (int i = 0; i < n - 1; ++i) {
        if (std::gcd(L[i], L[i + 1]) > d[i]) {
            conflict[i] = true;
        }
    }

    // DP to find the maximum independent set of changes considering conflicts
    // dp0[i]: max changes in first i elements, i-th NOT changed
    // dp1[i]: max changes in first i elements, i-th IS changed
    vector<int> dp0(n + 1, 0);
    vector<int> dp1(n + 1, -1000000);

    for (int i = 0; i < n; ++i) {
        dp0[i + 1] = max(dp0[i], dp1[i]);
        if (can_change[i]) {
            // Option 1: Previous was not changed
            dp1[i + 1] = dp0[i] + 1;
            // Option 2: Previous was changed, check for conflict
            if (i > 0 && !conflict[i - 1]) {
                dp1[i + 1] = max(dp1[i + 1], dp1[i] + 1);
            }
        }
    }

    cout << max(dp0[n], dp1[n]) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--) {
        solve();
    }
    return 0;
}
