#include <bits/stdc++.h>
#define int long long

using namespace std;

// 不能用set做，因爲set新增需要O(log n)
signed main() {
    int n;
    int ans = 0;
    cin >> n;

    int x[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int i = 0;
    while (i < n) {
        ans++;
        if (i + 1 < n) {
            while (x[i] == x[i + 1])
                i++;
        }
        i++;
    }
    cout << ans << endl;
}
