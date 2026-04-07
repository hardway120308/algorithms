#include "bits/stdc++.h"
#include <numeric>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int sum_a = accumulate(a, a + n, 0);

        if (sum_a % 2 == 1) {
            cout << "YES" << endl;
        } else {
            if ((k * n) % 2 == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
