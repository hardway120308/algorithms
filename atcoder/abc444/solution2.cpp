#include <bits/stdc++.h>
#define int long long
using namespace std;

int digit_sum(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

signed main() {
    int n;
    int k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (digit_sum(i) == k) {
            ans++;
        }
    }
    cout << ans << endl;
}
