#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t, x;
    cin >> t >> x;
    int a[t + 1];
    for (int i = 0; i <= t; i++) {
        cin >> a[i];
    }

    int reading = a[0];

    for (int i = 0; i <= t; i++) {
        bool has_changed = false;
        if (i >= 1) {
            if (abs(a[i] - reading) >= x) {
                reading = a[i];
                has_changed = true;
            }
            if (has_changed) {
                cout << i << ' ' << reading << endl;
            }
        } else {
            cout << i << ' ' << reading << endl;
        }
    }
}
