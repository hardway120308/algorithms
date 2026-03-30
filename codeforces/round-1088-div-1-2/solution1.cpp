#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n];
        for (int i = 0; i < n; i++)
            cin >> x[i];
        if (n >= 3) {
            for (int i = 0; i < n; i++) {
                cout << 2 << " ";
            }
        } else {
            for (int i = 0; i < n; i++) {
                cout << n << " ";
            }
        }
        cout << endl;
    }
}
