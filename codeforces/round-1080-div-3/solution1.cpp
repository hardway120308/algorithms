#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool contains_67 = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 67)
                contains_67 = true;
        }
        if (contains_67) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
