#include <bits/stdc++.h>
using namespace std;

const int MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        int S = x - y;
        int diff = abs(S);

        int ans;

        // Case 1: S = 0
        if (diff == 0) {
            ans = 1;
        } else {
            // count divisors of diff
            int cnt = 0;
            for (int i = 1; i * i <= diff; i++) {
                if (diff % i == 0) {
                    cnt++; // i
                    if (i * i != diff)
                        cnt++; // diff/i
                }
            }
            ans = cnt;
        }

        cout << ans % MOD << "\n";

        // construct array
        // x 個 1 + y 個 -1
        for (int i = 0; i < x; i++)
            cout << "1 ";
        for (int i = 0; i < y; i++)
            cout << "-1 ";
        cout << "\n";
    }

    return 0;
}
