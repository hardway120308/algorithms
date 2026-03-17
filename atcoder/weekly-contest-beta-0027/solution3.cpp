#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int k = 0;

    for (int i = 0; i < n - 1; i++) {
        // 確保i和i+1的距離小於k
        k = max(k, x[i + 1] - x[i]);
    }

    cout << k << endl;

    return 0;
}
