#include <bits/stdc++.h>

using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int sorted_a[n];
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x;
            sorted_a[i] = i + 1;
        }

        bool ans = true;

        for (int i = 0; i < n; i++) {
            if (a[i] == sorted_a[i]) {
                // already sorted
            } else {
                // try swap
                if (i + 1 <= n / 2) {
                    bool success = false;
                    // 2i,4i,8i,16i,..嘗試換
                    int k = 2;
                    while (k * (i + 1) <= n) {
                        int data = a[k * (i + 1) - 1];
                        if (data == sorted_a[i]) {
                            swap(a[i], a[k * (i + 1) - 1]);
                            success = true;
                            break;
                        } else {
                            k *= 2;
                        }
                    }
                    if (!success) {
                        ans = false;
                        break;
                    }
                } else {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
