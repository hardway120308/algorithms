#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x % 2 == 0 and y % 2 == 0) {
            cout << "YES" << endl;
        } else if (x % 2 == 0 and y % 2 == 1) {
            cout << "YES" << endl;

        } else if (x % 2 == 1 and y % 2 == 0) {
            cout << "YES" << endl;

        } else {
            cout << "NO" << endl;
        }
    }
}
