#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    int min_score = 0;
    int ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        cin >> x;
        if (x > 0) {
            if (i == k) {
                min_score = x;
            }
            if (x > 0 and i <= k) {
                ans++;
            }
            if (i > k and x >= min_score) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
