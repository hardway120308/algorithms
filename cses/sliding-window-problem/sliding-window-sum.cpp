#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;
    vector<int> arr(n);

    arr[0] = x;
    for (int i = 1; i < n; i++) {
        arr[i] = (arr[i - 1] * a + b) % c;
    }

    vector<int> prefix_sum(n);
    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    int ans = -123;

    int startPosition = 0;
    while (startPosition + k - 1 < n) {
        if (startPosition == 0) {
            ans = prefix_sum[startPosition + k - 1];
        } else {
            ans = ans xor (prefix_sum[startPosition + k - 1] - prefix_sum[startPosition - 1]);
        }
        startPosition += 1;
    }

    cout << ans << endl;
}